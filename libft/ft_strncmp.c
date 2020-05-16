/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 02:17:30 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/06/24 09:32:47 by pmoyaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i] &&
		(i < n - 1))
		i++;
	if ((unsigned char)str1[i] - (unsigned char)str2[i] > 0)
		return (1);
	else if ((unsigned char)str1[i] - (unsigned char)str2[i] < 0)
		return (-1);
	else
		return (0);
}
