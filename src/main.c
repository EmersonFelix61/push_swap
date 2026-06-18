/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:53:32 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 11:53:41 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	run_sort(t_bench *bench, t_stack **a, t_stack **b)
{
	if (bench->strategy == STRAT_SIMPLE)
	{
		bench->used_strategy = STRAT_SIMPLE;
		simple_sort(bench, a, b);
	}
	else if (bench->strategy == STRAT_MEDIUM)
	{
		bench->used_strategy = STRAT_MEDIUM;
		medium_sort(bench, a, b);
	}
	else if (bench->strategy == STRAT_COMPLEX)
	{
		bench->used_strategy = STRAT_COMPLEX;
		complex_sort(bench, a, b);
	}
	else
		bench->used_strategy = adaptive_sort(bench, a, b);
}

int	main(int argc, char **argv)
{
	int			*numbers;
	int			status;
	t_stack		*a;
	t_stack		*b;
	t_bench		bench;

	numbers = NULL;
	a = NULL;
	b = NULL;
	status = parser(argc, argv, &numbers, &bench);
	if (status == 0)
		return (0);
	if (status == -1)
		return (print_error());
	a = stack_builder(numbers, bench.numbers_count);
	if (!a)
		return (free(numbers), print_error());
	bench.disorder = ft_disorder(a);
	run_sort(&bench, &a, &b);
		print_bench(&bench);
	stack_free(&a);
	stack_free(&b);
	free(numbers);
	return (0);
}