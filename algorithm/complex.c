/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 09:58:24 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 09:58:24 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_rank(int *arr, int size, int value)
{
	int	left;
	int	mid;
	int	right;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == value)
			return (mid);
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

static	int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_pass(t_bench *bench, t_stack **a, t_stack **b, t_radix *radix)
{
	int	i;
	int	rank;

	i = 0;
	while (i < radix->size)
	{
		rank = get_rank(radix->arr, radix->size, (*a)->value);
		if (((rank >> radix->bit) & 1) == 0)
			push_pb(bench, a, b);
		else
			rotate_ra(bench, a);
		i++;
	}
	while (*b)
		push_pa(bench, a, b);
}

void	complex_sort(t_bench *bench, t_stack **a, t_stack **b)
{
	t_radix	radix;
	int		max_bits;

	if (!a || !*a || !b || is_sorted(*a))
		return ;
	radix.size = stack_size(*a);
	radix.arr = get_array(*a);
	if (!radix.arr)
		return ;
	radix.bit = 0;
	max_bits = get_max_bits(radix.size);
	while (radix.bit < max_bits)
	{
		radix_pass(bench, a, b, &radix);
		radix.bit++;
	}
	free(radix.arr);
}
