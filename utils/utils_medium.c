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
