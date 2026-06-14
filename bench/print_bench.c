#include "../includes/push_swap.h"

void	print_moves(t_bench *bench)
{
	int	i;

	i = 0;
	ft_putstr_fd("[bench] ops: ", 2);
	while (i < 11)
	{
		ft_putstr_fd(move_name(i), 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(bench->moves[i], 2);
		if (i < 10)
			ft_putstr_fd(" ", 2);
		i++;
	}
}

void	print_disorder_percent(double disorder)
{
	int	percent;

	percent = (int)(disorder * 10000 + 0.5);
	ft_putnbr_fd(percent / 100, 2);
	ft_putchar_fd('.', 2);
	if (percent % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(percent % 100, 2);
	ft_putchar_fd('%', 2);
}

void	print_bench(t_bench *bench)
{
	if (!bench || !bench->display)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder_percent(bench->disorder);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(bench->strategy), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(strategy_complexity(bench), 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench_moves(bench), 2);
	ft_putchar_fd('\n', 2);
	print_moves(bench);
	ft_putchar_fd('\n', 2);
}
