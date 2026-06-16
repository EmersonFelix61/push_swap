/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:54:54 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 11:55:04 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src || !dst)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	push_pa(t_bench *bench, t_stack **a, t_stack **b)
{
	if (!b || !*b || !a)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
	if (bench != NULL)
		++bench->moves[pa];
}

void	push_pb(t_bench *bench, t_stack **a, t_stack **b)
{
	if (!a || !*a || !b)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
	if (bench != NULL)
		++bench->moves[pb];
}
