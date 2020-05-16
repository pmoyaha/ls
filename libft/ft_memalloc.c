/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 08:52:44 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/06/17 16:37:30 by pmoyaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*dtr;

	dtr = malloc(size);
	if (dtr != NULL)
	{
		ft_bzero(dtr, size);
		return (dtr);
	}
	return (0);
}
