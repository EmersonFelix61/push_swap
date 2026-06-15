/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 10:04:24 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 10:04:41 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	bench_moves(t_bench *bench)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < 11)
	{
		total += bench->moves[i];
		i++;
	}
	return (total);
}

char	*strategy_name(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		return ("Simple");
	if (strategy == STRAT_MEDIUM)
		return ("Medium");
	if (strategy == STRAT_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*strategy_complexity(t_bench *bench)
{
	t_strategy	check_algo;

	if (bench->strategy == STRAT_ADAPTIVE)
		check_algo = bench->used_strategy;
	else
		check_algo = bench->strategy;
	if (check_algo == STRAT_SIMPLE)
		return ("O(n²)");
	if (check_algo == STRAT_MEDIUM)
		return ("O(n√n)");
	if (check_algo == STRAT_COMPLEX)
		return ("O(n log n)");
	return ("Adaptive");
}

char	*move_name(int move)
{
	if (move == 0)
		return ("sa");
	if (move == 1)
		return ("sb");
	if (move == 2)
		return ("ss");
	if (move == 3)
		return ("pa");
	if (move == 4)
		return ("pb");
	if (move == 5)
		return ("ra");
	if (move == 6)
		return ("rb");
	if (move == 7)
		return ("rr");
	if (move == 8)
		return ("rra");
	if (move == 9)
		return ("rrb");
	return ("rrr");
}
