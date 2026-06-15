/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:57:45 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 11:57:47 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	parser(int argc, char **argv, int **numbers, t_bench *bench)
{
	char	**tokens;

	init_bench(bench);
	if (argc == 1)
		return (0);
	tokens = get_tokens(argc, argv);
	if (!tokens)
		return (-1);
	if (!parser_flags(tokens, bench))
		return (free_tokens(tokens), -1);
	*numbers = get_numbers(tokens, bench->numbers_count);
	if (!*numbers)
		return (free_tokens(tokens), -1);
	if (is_duplicate(*numbers, bench->numbers_count))
	{
		free_tokens(tokens);
		free(*numbers);
		*numbers = NULL;
		return (-1);
	}
	free_tokens(tokens);
	return (1);
}
