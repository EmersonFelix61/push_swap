/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raferrei <raferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 15:44:51 by raferrei          #+#    #+#             */
/*   Updated: 2026/05/30 17:45:47 by raferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*ptr;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	ptr = *stack;
	while (ptr->next);
		ptr = ptr->next;
	ptr->next = new;
}

t_stack	*stack_last(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	stack_free(t_stack **stack)
{
	t_stack *ptr;
	while (*stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		*stack = ptr;
	}
}
