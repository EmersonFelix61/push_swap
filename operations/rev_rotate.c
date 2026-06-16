/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:55:38 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 11:55:38 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp1 = stack_last(*stack);
	tmp2 = stack_before_last(*stack);
	tmp2->next = NULL;
	tmp1->next = *stack;
	*stack = tmp1;
}

void	rev_rra(t_bench *bench, t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rev_rotate(a);
	write(1, "rra\n", 4);
	if (bench != NULL)
		++bench->moves[rra];
}

void	rev_rrb(t_bench *bench, t_stack **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rev_rotate(b);
	write(1, "rrb\n", 4);
	if (bench != NULL)
		++bench->moves[rrb];
}

void	rev_rrr(t_bench *bench, t_stack **a, t_stack **b)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
	if (bench != NULL)
		++bench->moves[rrr];
}
