/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:46:26 by avannier          #+#    #+#             */
/*   Updated: 2015/12/06 16:00:44 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;

	i = 0;
	if (s != 0 && (*f) != 0)
	{
		map = (char *)malloc(ft_strlen(s) + 1);
		while (s[i] != '\0')
		{
			map[i] = (*f)(s[i]);
			i++;
		}
		return (map);
	}
	return (0);
}
