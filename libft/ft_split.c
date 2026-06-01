/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:34:31 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/01 12:57:42 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static void	ft_free(char **s, int index)
{
	while (index > 0)
	{
		index--;
		free(s[index]);
	}
	free(s);
}

static char	**ft_fill_split(char **splitter, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		if (!s[i])
			break ;
		while (s[i] && s[i] != c)
			i++;
		splitter[j] = ft_substr(s, start, (i - start));
		if (!splitter[j])
		{
			ft_free(splitter, j);
			return (NULL);
		}
		j++;
	}
	splitter[j] = NULL;
	return (splitter);
}

char	**ft_split(char const *s, char c)
{
	char	**splitter;

	if (!s)
		return (NULL);
	splitter = ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!splitter)
		return (NULL);
	return (ft_fill_split(splitter, s, c));
}
