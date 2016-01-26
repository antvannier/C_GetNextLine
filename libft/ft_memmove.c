/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:33:09 by avannier          #+#    #+#             */
/*   Updated: 2015/12/04 16:33:11 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char *move;

	move = ft_memalloc(len);
	move = ft_strncpy(move, src, len);
	dest = (void *)ft_strncpy(dest, move, len);
	return (dest);
}
