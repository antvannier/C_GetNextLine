/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:34:35 by avannier          #+#    #+#             */
/*   Updated: 2015/12/04 16:35:00 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int nbr;

	nbr = 128;
	while (nbr > 0)
	{
		if (nbr <= octet)
		{
			write(1, "1", 1);
			octet = octet - nbr;
		}
		else
			write(1, "0", 1);
		nbr = nbr / 2;
	}
	write(1, "\n", 1);
}
