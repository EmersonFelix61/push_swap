#include "../includes/push_swap.h"

int	stack_size(t_stack *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_min_position(t_stack *stack)
{
	int	min;
	int	min_pos;
	int	i;

	if (!stack)
		return (-1);
	min = stack->value;
	min_pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_pos);
}

int	find_max_position(t_stack *stack)
{
	int	max;
	int	max_pos;
	int	i;

	if (!stack)
		return (-1);
	max = stack->value;
	max_pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (max_pos);
}

int	get_position(t_stack *stack, int value)
{
	int	pos;

	if (!stack)
		return (-1);
	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}