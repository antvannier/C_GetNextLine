/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:20:10 by nrandria          #+#    #+#             */
/*   Updated: 2015/12/01 17:15:49 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp2_src;
	unsigned char	*tmp3;
	size_t			i;

	tmp_dst = (unsigned char *)dst;
	tmp2_src = (unsigned char *)src;
	tmp3 = (unsigned char *)malloc(sizeof(unsigned char *) * len + 1);
	i = 0;
	while (i < len)
	{
		tmp3[i] = tmp2_src[i];
		i++;
	}
	tmp3[i] = '\0';
	i = 0;
	while (tmp3[i])
	{
		tmp_dst[i] = tmp3[i];
		i++;
	}
	return (dst);
}
