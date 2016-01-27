/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 08:19:47 by avannier          #+#    #+#             */
/*   Updated: 2016/01/27 12:29:53 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_removestrstr(int size, char *s1)
{
	char		*str;

	str = ft_strnew(ft_strlen(s1) - size);
	str = ft_strsub(s1, size + 1, ft_strlen(s1));
	return (str);
}

char			*ft_get_line(char *s1)
{
	char		*str;
	int			i;

	i = 0;
	while (s1[i] != '\n' && s1[i])
		i++;
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\n' && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strjoinfree(char *s1, char *s2)
{
	char		*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s2);
	return (tmp);
}

int				get_next_line(int fd, char **line)
{
	static char	*storage = NULL;
	char		*buf;
	int			ret;

	buf = ft_strnew(BUFF_SIZE);
	if (!buf || !line)
		return (-1);
	*line = (!storage) ? NULL : *line;
	storage = (!storage) ? ft_strnew(BUFF_SIZE) : storage;
	while (((ret = read(fd, buf, BUFF_SIZE)) > 0) && !ft_strchr(buf, '\n'))
	{
		buf[ret] = '\0';
		storage = ft_strjoinfree(storage, buf);
		buf = ft_strnew(BUFF_SIZE);
	}
	if (ret > 0)
		storage = ft_strjoinfree(storage, buf);
	else if (ret < 0)
		return (-1);
	if (ft_strlen(ft_removestrstr(ft_strlen(ft_get_line(storage)), storage))
			== 0 && !ft_strcmp(storage, "\0") && ft_strcmp(storage, "\n"))
		return (0);
	*line = ft_get_line(storage);
	storage = ft_removestrstr(ft_strlen(*line), storage);
	return (1);
}
