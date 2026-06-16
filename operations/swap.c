/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:56:28 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 11:56:46 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || ! *stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	swap_sa(t_bench *bench, t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap(a);
	write(1, "sa\n", 3);
	if (bench != NULL)
		++bench->moves[sa];
}

void	swap_sb(t_bench *bench, t_stack **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap(b);
	write(1, "sb\n", 3);
	if (bench != NULL)
		++bench->moves[sb];
}

void	swap_ss(t_bench *bench, t_stack **a, t_stack **b)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	if (bench != NULL)
		++bench->moves[ss];
}
