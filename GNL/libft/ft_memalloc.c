/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:22:28 by avannier          #+#    #+#             */
/*   Updated: 2016/01/04 10:35:08 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *str;

	if (!size)
		return (NULL);
	str = (void *)malloc(size);
	if (!str)
		return (NULL);
	ft_bzero((void *)str, size);
	return ((void *)str);
}
