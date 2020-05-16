/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:41:35 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/06/17 12:54:08 by pmoyaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	//size_t	i;
	char	*str;

	//i = 0;
	str = (char *)s;
	while (n--)
	{
		if (*str != (const char)c)
			str++;
		else
			return (str);
	}
	return (0);
}
