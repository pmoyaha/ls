/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 09:16:11 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/06/26 17:09:22 by pmoyaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *list, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*new_item;

	if (list)
	{
		new = f(list);
		new_item = new;
		list = list->next;
		while (list)
		{
			new_item->next = f(list);
			new_item = new_item->next;
			list = list->next;
		}
		return (new);
	}
	return (NULL);
}
