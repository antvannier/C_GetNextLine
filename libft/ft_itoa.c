/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:51:54 by nrandria          #+#    #+#             */
/*   Updated: 2015/12/02 14:44:18 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_max_neg(int n)
{
	if (n == -2147483648)
		return (1);
	else
		return (0);
}

static int	ft_itoa_size(int n)
{
	int		i;

	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		r;
	int		t;
	char	*str;

	if (!n)
		return ("0");
	if (ft_itoa_max_neg(n))
		return ("-2147483648");
	r = (n < 0) ? 0 : 1;
	n = (n < 0) ? n * -1 : n;
	i = ft_itoa_size(n);
	t = n;
	str = ft_memalloc(i);
	while (t)
	{
		str[i - r] = (t % 10) + 48;
		i--;
		t /= 10;
	}
	if (!r)
		str[0] = '-';
	return (str);
}
