/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 05:00:54 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/05/25 05:07:14 by pmoyaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t y;
	size_t destlen;
	size_t sourcelen;
	size_t res;

	y = 0;
	destlen = ft_strlen(dst);
	sourcelen = ft_strlen(src);
	res = sourcelen + destlen;
	if (dstsize < destlen)
		return (sourcelen + dstsize);
	while (src[y] && (dstsize > destlen + 1))
		dst[destlen++] = src[y++];
	dst[destlen] = '\0';
	return (res);
}
