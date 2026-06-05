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