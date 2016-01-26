/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:46:53 by avannier          #+#    #+#             */
/*   Updated: 2015/12/04 16:46:55 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while ((unsigned char)s2[j] != '\0' && (int)n > j)
	{
		s1[i] = (unsigned char)s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
