/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:24:13 by nrandria          #+#    #+#             */
/*   Updated: 2016/01/11 15:57:37 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_push_front(t_list **list, void *content, size_t content_size)
{
	t_list	*tmp;

	if (tmp)
	{
		tmp = ft_create_elem(content, content_size);
		tmp->next = *list;
		*list = tmp;
	}
	else
		tmp = ft_create_elem(content, content_size);
}
