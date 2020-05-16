/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 23:07:32 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/06/27 08:05:19 by pmoyaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_num_words(char const *s, char c)
{
	size_t i;
	size_t words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		if (s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static	size_t	ft_num_char(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * ft_num_words(s, c) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			str[x] = ft_strsub(s, i, ft_num_char(&s[i], c));
			x++;
			i = i + ft_num_char(&s[i], c);
		}
		while (s[i] && s[i] == c)
			i++;
	}
	str[x] = NULL;
	return (str);
}
