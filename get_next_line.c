/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:43:45 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/03 00:36:16 by student          ###   ########.fr       */
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

static int	del_list(t_list **lst, int fd, char *line)
{
	t_list	*tmp;
	t_list	*bgn;
	t_list	*list;

	bgn = 0;
	list = *lst;
	free(line);
	while (list)
	{
		if (list->fd == fd)
		{
			free(list->content);
			tmp = list->next;
			list->next = 0;
			free(list);
			if (bgn)
				bgn->next = tmp;
			else
				*lst = tmp;
			return (-1);
		}
		bgn = list;
		list = list->next;
	}
	return (-1);
}

static int	add_list(char *buf, t_list **lst, int fd)
{
	char	*line;
	t_list	*nlist;

	if (!check_remainder(*lst, fd))
	{
		if (!(line = (char *)malloc(sizeof(char) * 1)))
			return (0);
		*line = 0;
		if (!ft_lstadd_back(lst, ft_lstnew(line, fd)))
		{
			free (line);
			return (0);
		}
	}
	nlist = *lst;
	while (nlist->fd != fd)
		nlist = nlist->next;
	if (!(line = ft_strjoin(nlist->content, buf)))
		return (0);
	free(nlist->content);
	nlist->content = line;
	return (1);
}

static int	submit_line(t_list *lst, int fd, char **line)
{
	size_t	len;
	char	*tmp;

	while (lst)
	{
		if (lst->fd == fd)
		{
			free(line);
			if (ft_strchr(buf, '\n'))
				len = ft_strchr(lst->content, '\n') - lst->content;
			else
				len = ft_strchr(lst->content, '\0') - lst->content;
			if (!(*line = ft_substr(lst->content, 0, len)))
				return (0);
			if (!(tmp = ft_substr(lst->content, len + 1,\
						ft_strchr(lst->content, '\0') - lst->content)))
				return (0);
			free(lst->content);
			lst->content = tmp;
		}
		lst = lst->next;
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static	t_list	*lst;
	char			buf[BUFFER_SIZE + 1];
	int				rt;

	if (!(*line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	**line = 0;
	while (check_remainder(lst, fd) < 2)
	{
		if ((rt = read(fd, buf, BUFFER_SIZE)) < 1)
		{
<<<<<<< HEAD
			if (!submit_line(lst, fd, line))
				return (del_list(&lst, fd, *line));
			del_list(&lst, f, *line);
=======
			if (check_remainder(lst, fd) == 1)
				submit_line(&lst, fd, line);
			else
			{
				if (!(*line = ft_strjoin("\0", "\0")))
					return (-1);
			}
>>>>>>> refs/remotes/origin/master
			return (rt);
		}
		buf[rt] = 0;
		if (!add_list(buf, &lst, fd))
			return (del_list(&lst, fd, *line));
	}
	if (!submit_line(lst, fd, line))
		return (del_list(&lst, fd, *line));
	return (1);
}
