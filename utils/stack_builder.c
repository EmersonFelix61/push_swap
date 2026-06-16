/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:58:18 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 11:58:20 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_builder(int *numbers, int size)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	i = 0;
	stack = NULL;
	while (i < size)
	{
		new = new_stack(numbers[i]);
		if (!new)
		{
			stack_free(&stack);
			return (NULL);
		}
		add_back(&stack, new);
		i++;
	}
	return (stack);
}
