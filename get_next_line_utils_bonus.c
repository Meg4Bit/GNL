/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 23:10:28 by ametapod          #+#    #+#             */
/*   Updated: 2020/05/30 23:10:28 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1)
		return (0);
	str = (char *)malloc(sizeof(char) * ((ft_strchr(s1, '\0') - s1) +\
			(ft_strchr(s2, '\0') - s2) + 1));
	if (str)
	{
		i = 0;
		while (*s1)
			str[i++] = *s1++;
		while (*s2)
			str[i++] = *s2++;
		str[i] = 0;
		return (str);
	}
	return (0);
}
