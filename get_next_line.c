/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:43:45 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/02 00:31:52 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_remainder(t_list *lst, int fd)
{
	while (lst)
	{
		if (lst->fd == fd)
		{
			lst = lst->next;
			while (lst)
			{
				if (lst->fd == fd)
					return (2);
				lst = lst->next;
			}
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

static int	remalloc_list(char *ptr, t_list **lst, int fd)
{
	int		i;
	t_list	*last;
	char	*line;

	if (*ptr == 0 || !(check_remainder(*lst, fd)))
	{
		if (!ft_lstadd_back(lst, ft_lstnew(ptr, fd)))
			return (0);
	}
	else
	{
		last = ft_lstlast(*lst, fd);
		if (!(line = (char *)malloc(sizeof(char) *\
			((ft_strchr(last->content, '\0') - (char *)last->content) +\
				(ft_strchr(ptr, '\0') - ptr) + 1))))
			return (0);
		i = 0;
		while (*((char *)last->content))
			line[i++] = *((char *)last->content++);
		while (*ptr)
			line[i++] = *ptr++;
		line[i] = 0;
		free(last->content);
		last->content = line;
		//free(ptr);
	}
	return (1);
}

static int	add_list(char *buf, t_list **lst, int fd)
{
	int		len;
	int		i;
	char	*ptr;

	while (*buf)
	{
		if (ft_strchr(buf, '\n'))
			len = ft_strchr(buf, '\n') - buf;
		else
			len = ft_strchr(buf, '\0') - buf;
		if (*buf == '\n')
			buf++;
		if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		i = 0;
		while (i < len)
			ptr[i++] = *buf++;
		ptr[i] = 0;
		if (!remalloc_list(ptr, lst, fd))
			return (0);
	}
	return (1);
}

static int	submit_line(t_list **lst, int fd, char **line)
{
	t_list	*tmp;
	t_list	*bgn;
	t_list	*list;

	bgn = 0;
	list = *lst;
	while (list)
	{
		if (list->fd == fd)
		{
			*line = list->content;
			tmp = list->next;
			list->next = NULL;
			free(list);
			if (bgn)
				bgn->next = tmp;
			else
				*lst = tmp;
			return (1);
		}
		bgn = list;
		list = list->next;
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static	t_list	*lst;
	char			buf[BUFFER_SIZE + 1];
	int				rt;

	while (check_remainder(lst, fd) < 2)
	{
		if ((rt = read(fd, buf, BUFFER_SIZE)) < 1)
		{
			if (check_remainder(lst, fd) == 1)
				return (submit_line(&lst, fd, line));
			return (rt);
		}
		buf[rt] = 0;
		if (!add_list(buf, &lst, fd))
		{
			//del;
			return (-1);
		}
	}
	return (submit_line(&lst, fd, line));
}
