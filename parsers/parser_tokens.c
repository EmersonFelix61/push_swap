/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:57:50 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 11:57:57 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	len_args(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len += ft_strlen(argv[i]);
		if (i < argc - 1)
			len ++;
		i++;
	}
	return (len);
}

char	*join_args(int argc, char **argv)
{
	char	*joined;
	int		i;
	int		j;
	int		k;

	joined = malloc(sizeof(char) * (len_args(argc, argv) + 1));
	if (!joined)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (free(joined), NULL);
		j = 0;
		while (argv[i][j])
			joined[k++] = argv[i][j++];
		if (i < argc - 1)
			joined[k++] = ' ';
		i++;
	}
	joined[k] = '\0';
	return (joined);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

char	**get_tokens(int argc, char **argv)
{
	char	**tokens;
	char	*joined;

	if (argc == 1)
		return (NULL);
	joined = join_args(argc, argv);
	if (!joined)
		return (NULL);
	tokens = ft_split(joined, ' ');
	free(joined);
	if (!tokens)
		return (NULL);
	if (!tokens[0])
	{
		free_tokens(tokens);
		return (NULL);
	}
	return (tokens);
}
