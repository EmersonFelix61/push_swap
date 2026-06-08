#include "../includes/push_swap.h"

double	ft_disorder(t_stack *stack)
{
	double	mistakes;
	double	total_pairs;
	t_stack	*start;
	t_stack	*next_start;

	mistakes = 0;
	total_pairs = 0;
	start = stack;
	if (!stack || !stack->next)
		return (0);
	while (start)
	{
		next_start = start->next;
		while (next_start)
		{
			++total_pairs;
			if (start->value > next_start->value)
				++mistakes;
		next_start = next_start->next;
		}
		start = start->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}

int	main(int argc, char **argv)
{
	int			*numbers;
	int			status;
	t_stack		*a;
	t_stack		*b;
	t_bench		bench;

	numbers = NULL;
	a = NULL;
	b = NULL;
	status = parser(argc, argv, &numbers, &bench);
	if (status == 0)
		return (0);
	if (status == -1)
		return (print_error());
	a = stack_builder(numbers, bench.numbers_count);
	if (!a)
		return (free(numbers), print_error());
	bench.disorder = ft_disorder(a);
	//algoritmo aqui
	stack_free(&a);
	stack_free(&b);
	free(numbers);
	return (0);
}