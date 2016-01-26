/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:50:28 by avannier          #+#    #+#             */
/*   Updated: 2015/12/04 16:50:29 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int n;

	i = 0;
	n = 0;
	while (s1[n])
	{
		while (s1[n] == s2[i] && s2[i])
		{
			i++;
			n++;
		}
		if (s2[i] == '\0')
			return ((char*)s1 + n - i);
		else
		{
			n = n - i;
			i = 0;
		}
		n++;
	}
	if (s1[n] == s2[i])
		return ((char*)s1 + n);
	return (NULL);
}
