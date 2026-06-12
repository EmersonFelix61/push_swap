#include "../includes/push_swap.h"

static void	run_sort(t_bench *bench, t_stack **a, t_stack **b)
{
	if (bench->strategy == STRAT_SIMPLE)
		simple_sort(bench, a, b);
	else if (bench->strategy == STRAT_MEDIUM)
		medium_sort(bench, a, b);
	else if (bench->strategy == STRAT_COMPLEX)
		complex_sort(bench, a, b);
	else
		adaptive_sort(bench, a, b);
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
	run_sort(&bench, &a, &b);
	stack_free(&a);
	stack_free(&b);
	free(numbers);
	return (0);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}
