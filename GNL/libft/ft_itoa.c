/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:19:25 by avannier          #+#    #+#             */
/*   Updated: 2015/12/06 22:56:20 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_nbr(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

char		*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*str;

	sign = 1;
	len = ft_itoa_nbr(n);
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[len] = '\0';
	if (n < 0)
	{
		sign = -1;
		str[0] = '-';
	}
	len = len - 1;
	while (n)
	{
		str[len] = (((n % 10) * sign) + '0');
		len--;
		n = n / 10;
	}
	return (str);
}
