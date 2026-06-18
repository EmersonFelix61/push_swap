/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 09:58:11 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 09:58:16 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

double	ft_disorder(t_stack *stack)
{
	double	mistakes;
	double	total_pairs;
	t_stack	*start;
	t_stack	*next_start;

	mistakes = 0;
	total_pairs = 0;
	start = stack;
	if (!stack || !stack->next)
		return (0);
	while (start)
	{
		next_start = start->next;
		while (next_start)
		{
			++total_pairs;
			if (start->value > next_start->value)
				++mistakes;
			next_start = next_start->next;
		}
		start = start->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}

static int	tiny_sort(t_bench *bench, t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 2)
		sort_two(bench, a);
	else if (stack_size(*a) == 3)
		sort_three(bench, a);
	else if (stack_size(*a) == 4)
		sort_four(bench, a, b);
	else if (stack_size(*a) == 5)
		sort_five(bench, a, b);
	else
		return (0);
	return (1);
}

t_strategy	adaptive_sort(t_bench *bench, t_stack **a, t_stack **b)
{
	int		size;
	double	disorder;

	if (!a || !*a || !b || is_sorted(*a))
		return (STRAT_SIMPLE);
	disorder = ft_disorder(*a);
	bench->disorder = disorder;
	size = stack_size(*a);
	if (size >= 2 && size <= 5)
	{
		tiny_sort(bench, a, b);
		if (disorder < 0.2)
			return (STRAT_SIMPLE);
		if (disorder > 0.5)
			return (STRAT_COMPLEX);
		if (disorder > 0.2 && disorder < 0.5)
			return (STRAT_MEDIUM);
	}
	if (disorder < 0.2)
		return (simple_sort(bench, a, b), STRAT_SIMPLE);
	else if (disorder < 0.5)
		return (medium_sort(bench, a, b), STRAT_MEDIUM);
	complex_sort(bench, a, b);
	return (STRAT_COMPLEX);
}
