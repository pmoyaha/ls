/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:39:07 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/06/22 01:21:43 by pmoyaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*dest;
	const char	*source;
	int			x;

	i = 0;
	dest = (char *)dst;
	source = (const char *)src;
	x = (int)n;
	if (source == NULL && dest == NULL)
		return (NULL);
	while (i < x)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
