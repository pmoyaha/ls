/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:20:00 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/06/18 10:31:56 by pmoyaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*temp;
	size_t	len;
	size_t	i;

	if (!s)
	{
		return (NULL);
	}
	len = (size_t)ft_strlen(s);
	i = 0;
	if (!(temp = (char *)malloc(len + 1)))
	{
		return (NULL);
	}
	while (len > i)
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
