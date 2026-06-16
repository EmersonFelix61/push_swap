/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:49:06 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/16 11:49:12 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	read_moves(t_stack **a, t_stack **b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		if (!checker_apply_instruction(instruction, a, b))
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

static	int	is_flag(char *s, char *flag)
{
	return (ft_strncmp(s, flag, ft_strlen(flag) + 1) == 0);
}

static	int	has_flags(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i], "--bench")
			|| is_flag(argv[i], "--simple")
			|| is_flag(argv[i], "--medium")
			|| is_flag(argv[i], "--complex")
			|| is_flag(argv[i], "--adaptive"))
			return (1);
		i++;
	}
	return (0);
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
	if (has_flags(argc, argv))
		return (print_error());
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
	return (checker_result(a, b), stack_free(&a), stack_free(&b), 0);
}
