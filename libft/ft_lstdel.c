/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:59:16 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/06/26 15:47:26 by pmoyaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*elem;
	t_list	*next;

	elem = *alst;
	while (elem)
	{
		del(elem->content, elem->content_size);
		next = elem->next;
		free(elem);
		elem = next;
	}
	*alst = NULL;
}
