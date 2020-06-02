/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 23:10:32 by ametapod          #+#    #+#             */
/*   Updated: 2020/05/30 23:10:32 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
char			*ft_strjoin(char const *s1, char const *s2);

#endif
