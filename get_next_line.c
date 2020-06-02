/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:43:45 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/02 22:20:36 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_remainder(t_list *lst, int fd)
{
	while (lst)
	{
		if (lst->fd == fd)
		{
			if (ft_strchr(lst->content, '\n'))
				return (2);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

static int	remalloc_list(char *ptr, t_list **lst, int fd)
{
	t_list	*last;
	char	*line;

	if (!(last = ft_lstlast(*lst, fd)))
	{
		if (!ft_lstadd_back(lst, ft_lstnew(ptr, fd)))
			return (0);
		return (1);
	}
	if (ft_strchr(last->content, '\n'))
	{
		if (!ft_lstadd_back(lst, ft_lstnew(ptr, fd)))
			return (0);
	}
	else
	{
		if (!(line = ft_strjoin(last->content, ptr)))
			return (0);
		free(last->content);
		last->content = line;
		free(ptr);
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
			len = ft_strchr(buf, '\n') - buf + 1;
		else
			len = ft_strchr(buf, '\0') - buf;
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
			if (ft_strchr(*line, '\n'))
				(*line)[ft_strchr(*line, '\n') - *line] = 0;
			tmp = list->next;
			list->next = 0;
			free(list);
			bgn ? (bgn->next = tmp) :\
						(*lst = tmp);
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
	static	int		rt;

	while (check_remainder(lst, fd) < 2)
	{
		if ((rt = read(fd, buf, BUFFER_SIZE)) < 1)
		{
			if (check_remainder(lst, fd) == 1)
				submit_line(&lst, fd, line);
			else
				*line = ft_strjoin("\0", "\0");
			return (rt);
		}
		buf[rt] = 0;
		if (!add_list(buf, &lst, fd))
			return (-1);
	}
	return (submit_line(&lst, fd, line));
}
