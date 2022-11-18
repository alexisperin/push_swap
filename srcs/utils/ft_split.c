/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:34:15 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 22:43:56 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	size_splits(const char *str, char c)
{
	size_t	i;
	size_t	size;

	if (!str)
		return (0);
	i = 0;
	size = 1;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

static char	*get_substring(const char *str, char c)
{
	size_t	len;
	size_t	i;
	char	*substr;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (i < len)
	{
		substr[i] = str[i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}

static char	**free_splits(char **splits, size_t i)
{
	while (i)
	{
		i--;
		free(splits[i]);
	}
	free(splits);
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**splits;
	size_t	i;
	size_t	j;

	splits = malloc(size_splits(str, c) * sizeof(char *));
	if (!str || !splits)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			splits[j] = get_substring(&str[i], c);
			if (!splits[j])
				return (free_splits(splits, j));
			j++;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	splits[j] = 0;
	return (splits);
}
