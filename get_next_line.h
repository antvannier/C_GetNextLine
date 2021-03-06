/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:25:27 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 11:06:26 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../includes/libft.h"
# define BUFF_SIZE 1
# define MAP 0
# define F ft_bootstrap

typedef struct		s_gnl
{
	char			b[BUFF_SIZE + 1];
	int				fd;
	char			*t;
	int				r;
	int				i;
	char			*s;
	char			**l;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(int fd, char **line);
void				ft_bootstrap(char **line);

#endif
