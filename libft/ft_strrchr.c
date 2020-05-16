/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 04:08:34 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/06/04 10:24:15 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	char	chr;
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + 1;
	chr = (char)c;
	str = (char *)s1;
	while (len > 0)
	{
		len--;
		if (str[len] == chr)
		{
			return (str + len);
		}
	}
	return (0);
}
