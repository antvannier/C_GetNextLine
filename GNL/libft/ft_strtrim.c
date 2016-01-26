/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:50:52 by avannier          #+#    #+#             */
/*   Updated: 2015/12/06 16:07:49 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	trim = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = 0;
	while (i <= len)
		trim[j++] = s[i++];
	trim[j] = '\0';
	return (trim);
}
