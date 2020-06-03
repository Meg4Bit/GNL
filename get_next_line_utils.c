/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:53:18 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/02 22:09:49 by student          ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		strleng;
	char	*sub;

	if (!s)
		return (0);
	strleng = (ft_strchr(s, '\0') - s);
	if (start >= strleng)
		len = 0;
	else
		if (len > strleng - start)
			len = strleng - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub)
	{
		strleng = 0;
		while (len-- && s[start])
			sub[strleng++] = s[start++];
		sub[strleng] = 0;
		return (sub);
	}
	return (0);
}