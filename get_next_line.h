/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:45:24 by ametapod          #+#    #+#             */
/*   Updated: 2020/05/31 23:46:33 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	int				fd;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
t_list			*ft_lstnew(void *content, int fd);
void			*ft_lstadd_back(t_list **lst, t_list *new);
char			*ft_strchr(const char *s, int c);
t_list			*ft_lstlast(t_list *lst, int fd);

#endif
