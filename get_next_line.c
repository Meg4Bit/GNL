/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:43:45 by ametapod          #+#    #+#             */
/*   Updated: 2020/05/31 16:40:08 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	check_remainder()
{
	return (0);
}

static	int	submit_line()
{
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static	t_list	lst;
	char			buf[BUFFER_SIZE + 1];
	int				rt;

	rt = 1;
	while (check_remainder() < 2 && rt > 0)
	{
		if ((rt = read(fd, buf, BUFFER_SIZE)) < 1)
		{
			if (check_remainder() == 1)
				return (submit_line());
			return (rt);
		}
		buf[rt] = 0;
		*line = buf;
		ft_lstadd_back(&lst, ft_lstnew());
	}
	return (submit_line());
}
