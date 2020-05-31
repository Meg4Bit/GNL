/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:43:45 by ametapod          #+#    #+#             */
/*   Updated: 2020/05/31 22:32:53 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	add_list(char *buf, t_list **lst, int fd)
{
	int 	len;
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
		if (!ft_lstadd_back(lst, ft_lstnew(ptr, fd)))
			return (0);
	}
	return (1);
}

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

static int	submit_line(t_list *lst, int fd, char **line)
{
	while (lst)
	{
		if (lst->fd == fd)
		{
			*line = lst->content;
			lst->next = NULL;
			free(lst);
			return (1);
		}
		lst = lst->next;
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
				return (submit_line(lst, fd, line));
			return (rt);
		}
		buf[rt] = 0;
		if (!add_list(buf, &lst, fd))
		{
			//del;
			return (-1);
		}
	}
	return (submit_line(lst, fd, line));
}
