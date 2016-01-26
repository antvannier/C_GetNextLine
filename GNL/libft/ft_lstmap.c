/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:21:53 by avannier          #+#    #+#             */
/*   Updated: 2015/12/04 16:21:55 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *maillon_list;
	t_list *begin_list;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((maillon_list = ft_lstnew(lst->content, lst->content_size)) == NULL)
		return (NULL);
	maillon_list = f(maillon_list);
	begin_list = maillon_list;
	lst = lst->next;
	while (lst)
	{
		if ((maillon_list->next = ft_lstnew(lst->content, lst->content_size))
		== NULL)
			return (NULL);
		maillon_list->next = f(maillon_list->next);
		maillon_list = maillon_list->next;
		lst = lst->next;
	}
	return (begin_list);
}
