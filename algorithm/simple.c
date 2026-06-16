/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 09:59:07 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 10:00:07 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_insert_pos(t_stack *a, int value)
{
	int		pos;
	t_stack	*cur;
	t_stack	*next;

	pos = 0;
	cur = a;
	while (cur)
	{
		next = cur->next;
		if (!next)
			next = a;
		if (value > cur->value && value < next->value)
			return (pos + 1);
		if (cur->value > next->value
			&& (value > cur->value || value < next->value))
			return (pos + 1);
		cur = cur->next;
		pos++;
	}
	return (0);
}

static int	cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

static	int	combined_cost(int pos_a, int size_a, int pos_b, int size_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = cost(pos_a, size_a);
	cost_b = cost(pos_b, size_b);
	if ((pos_a <= size_a / 2) == (pos_b <= size_b / 2))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

static void	find_best(t_stack *a, t_stack *b, int *best_pos_a, int *best_pos_b)
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;
	int	best;

	size_a = stack_size(a);
	size_b = stack_size(b);
	best = INT_MAX;
	pos_b = 0;
	while (b)
	{
		pos_a = find_insert_pos(a, b->value);
		if (combined_cost(pos_a, size_a, pos_b, size_b) < best)
		{
			best = combined_cost(pos_a, size_a, pos_b, size_b);
			*best_pos_a = pos_a;
			*best_pos_b = pos_b;
		}
		b = b->next;
		pos_b++;
	}
}

void	simple_sort(t_bench *bench, t_stack **a, t_stack **b)
{
	int	pos_a;
	int	pos_b;

	if (!a || !*a || is_sorted(*a))
		return ;
	while (stack_size(*a) > 3)
		push_pb(bench, a, b);
	sort_three(bench, a);
	while (*b)
	{
		find_best(*a, *b, &pos_a, &pos_b);
		picker_ra_rra(bench, a, pos_a);
		picker_rb_rrb(bench, b, pos_b);
		push_pa(bench, a, b);
	}
	move_min_top(bench, a);
}
