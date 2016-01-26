/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:10:12 by avannier          #+#    #+#             */
/*   Updated: 2016/01/26 16:11:01 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static void ft_return(char **line, char **save)
{
    size_t  len;
    char    *tmp;

    len = ft_strchr(*save, '\n') - *save;
    tmp = *save;
    *line = ft_strsub(tmp, 0, len);
    *save = ft_strdup(tmp + len + 1);
    if ((*save) == NULL)
        ft_strdel(save);
    free(tmp);
}

static int  ft_eof(char **line, char **save)
{
    *line = ft_strdup(*save);
    ft_strdel(save);
    return (0);
/*verif que la valeur du read soit =0 */
}

static int  ft_error(char **save)
{
    if (*save)
        ft_strdel(save);
    return (-1);
}

int         get_next_line(int fd, char **line)
{
    char        buff[BUFF_SIZE + 1];
    int         ret;
    static char *save = NULL;
    char        *tmp;

/*verif condition si line exciste */

    ret = 0;
    if (fd == -1 || BUFF_SIZE <= 0)
        return (ft_error(&save));
    if (save == NULL)
        save = ft_strnew(BUFF_SIZE + 1);
    while (save != NULL && ft_strchr(save, '\n') == NULL
		   && ((ret = read(fd, buff, BUFF_SIZE)) > 0))
    {
        buff[ret] = '\0';
        tmp = save;
        save = ft_strjoin(tmp, buff);
        free(tmp);
    }
    if (ret == -1)
        return (-1);
    if (ret < BUFF_SIZE && ft_strchr(save, '\n') == NULL)
        return (ft_eof(line, &save));
    ft_return(line, &(save));
    return (1);
}
