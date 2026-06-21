/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorith_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:58:29 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 11:58:47 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_min_top(t_bench *bench, t_stack **a)
{
	int	pos;

	pos = find_min_position(*a);
	picker_ra_rra(bench, a, pos);
}

static void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static	void	heap_sort(int *arr, int size, int root)
{
	int	largest;
	int	left;
	int	right;

	largest = root;
	left = 2 * root + 1;
	right = 2 * root + 2;
	if (left < size && arr[left] > arr[largest])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;
	if (largest != root)
	{
		swap_int(&arr[root], &arr[largest]);
		heap_sort(arr, size, largest);
	}
}

void	sort_array(int *arr, int size)
{
	int	i;

	if (!arr || size <= 1)
		return ;
	i = size / 2 - 1;
	while (i >= 0)
	{
		heap_sort(arr, size, i);
		i--;
	}
	i = size - 1;
	while (i > 0)
	{
		swap_int(&arr[0], &arr[i]);
		heap_sort(arr, i, 0);
		i--;
	}
}
