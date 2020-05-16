/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:00:28 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/05/22 12:03:25 by pmoyaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t p;

	p = 0;
	while (p < n && src[p])
	{
		dst[p] = src[p];
		p++;
	}
	while (p < n)
	{
		dst[p] = '\0';
		p++;
	}
	return (dst);
}
