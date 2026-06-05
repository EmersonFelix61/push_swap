#include "../includes/push_swap.h"

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
		return (free(numbers),print_error());
	//algoritmo aqui
	stack_free(&a);
	stack_free(&b);
	free(numbers);
	return (0);
}

/*
int main(int argc, char **argv)
{
	int			*numbers;
	int			i;
	int			status;
	t_bench		bench;
	t_config	config;

	numbers = NULL;
	status = parser_input(argc, argv, &numbers, &config, &bench);
	ft_printf("status = %d\n", status);
	if (status == -1)
		return (print_error());
	if (bench.display)
	{
		ft_printf("Numbers count: %d\n", config.numbers_count);
		ft_printf("Strategy: %d\n", config.strategy);
		ft_printf("Bench display: %d\n", bench.display);
		ft_printf("Bench disorder nao calculada ainda\n");
	}
	else
	{
		ft_printf("Numbers count: %d\n", config.numbers_count);
		ft_printf("Bench display: OFF\n");
	}
	i = 0;
	while (i < config.numbers_count)
	{
		ft_printf("%d\n", numbers[i]);
		i++;
	}	
	free(numbers);
	return (0);
}
*/