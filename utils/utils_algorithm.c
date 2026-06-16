/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:58:54 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 12:00:11 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	int	*array;
	int	size;
	int	i;

	size = stack_size(stack);
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (array);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
		}
		i++;
	}
}

int	*get_array(t_stack *stack)
{
	int	size;
	int	*array;

	size = stack_size(stack);
	array = stack_to_array(stack);
	if (!array)
		return (NULL);
	sort_array(array, size);
	return (array);
}

void	picker_ra_rra(t_bench *bench, t_stack **a, int pos)
{
	int	size;

	if (!a || !*a)
		return ;
	if (pos == 0)
		return ;
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos--)
			rotate_ra(bench, a);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rev_rra(bench, a);
	}
}

void	picker_rb_rrb(t_bench *bench, t_stack **b, int pos)
{
	int	size;

	if (!b || !*b)
		return ;
	if (pos == 0)
		return ;
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos--)
			rotate_rb(bench, b);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rev_rrb(bench, b);
	}
}
