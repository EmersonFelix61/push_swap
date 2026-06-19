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

static void	tiny_sort(t_bench *bench, t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 2)
		sort_two(bench, a);
	else if (stack_size(*a) == 3)
		sort_three(bench, a);
	else if (stack_size(*a) == 4)
		sort_four(bench, a, b);
	else if (stack_size(*a) == 5)
		sort_five(bench, a, b);
}

static t_strategy	get_regime(double disorder)
{
	if (disorder < 0.2)
		return (STRAT_SIMPLE);
	if (disorder < 0.5)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

t_strategy	adaptive_sort(t_bench *bench, t_stack **a, t_stack **b)
{
	int			size;
	t_strategy	regime;

	if (!bench || !a || !*a || !b)
		return (STRAT_SIMPLE);
	regime = get_regime(bench->disorder);
	if (is_sorted(*a))
		return (regime);
	size = stack_size(*a);
	if (size >= 2 && size <= 5)
	{
		tiny_sort(bench, a, b);
		return (regime);
	}
	if (regime == STRAT_SIMPLE)
		simple_sort(bench, a, b);
	else if (regime == STRAT_MEDIUM)
		medium_sort(bench, a, b);
	else
		complex_sort(bench, a, b);
	return (regime);
}
