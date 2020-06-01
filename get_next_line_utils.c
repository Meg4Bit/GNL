/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:53:18 by ametapod          #+#    #+#             */
/*   Updated: 2020/05/31 23:46:18 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content, int fd)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = content;
		tmp->fd = fd;
		tmp->next = NULL;
	}
	return (tmp);
}

void	*ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (new)
	{
		if (*lst)
		{
			ptr = *lst;
			while ((*lst)->next)
				*lst = (*lst)->next;
			(*lst)->next = new;
			*lst = ptr;
		}
		else
			*lst = new;
	}
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

t_list	*ft_lstlast(t_list *lst, int fd)
{
	t_list *ptr;

	ptr = 0;
	while (lst)
	{
		if (lst->fd == fd)
			ptr = lst;
		lst = lst->next;
	}
	return (ptr);
}