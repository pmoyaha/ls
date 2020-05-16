/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 03:50:35 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/06/04 10:25:41 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	size_t	i;
	char	chr;
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	chr = (char)c;
	str = (char *)s1;
	while (i <= len)
	{
		if (str[i] == chr)
		{
			return (str + i);
		}
		i++;
	}
	return (0);
}
