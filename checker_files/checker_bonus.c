#include "../includes/checker_bonus.h"

static int	read_moves(t_stack **a, t_stack **b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		if (!bonus_checker_apply_instruction(instruction, a, b))
			return (free(instruction), 0);
		free(instruction);
		instruction = get_next_line(0);
	}
	return (1);
}

static void	checker_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	int			status;
	int			*numbers;
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
	free(numbers);
	if (!a)
		return (print_error());
	if (!read_moves(&a, &b))
		return (stack_free(&a), stack_free(&b), print_error());
	checker_result(a, b);
	stack_free(&a);
	stack_free(&b);
	return (0);
}