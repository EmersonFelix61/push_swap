#include "../includes/push_swap.h"

static int	bench_moves(t_bench *bench)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < 11)
	{
		total += bench->moves[i];
		i++;
	}
	return (total);
}

char	*strategy_name(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		return ("Simple");
	if (strategy == STRAT_MEDIUM)
		return ("Medium");
	if (strategy == STRAT_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*strategy_complexity(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		return ("O(n²)");
	if (strategy == STRAT_MEDIUM)
		return ("O(n√2n)");
	if (strategy == STRAT_COMPLEX)
		return ("O(nlogn)");
	else
		return ("Adaptive");
}

char	*move_name(int move)
{
	if (move == 0)
		return ("sa");
	if (move == 1)
		return ("sb");
	if (move == 2)
		return ("ss");
	if (move == 3)
		return ("pa");
	if (move == 4)
		return ("pb");
	if (move == 5)
		return ("ra");
	if (move == 6)
		return ("rb");
	if (move == 7)
		return ("rr");
	if (move == 8)
		return ("rra");
	if (move == 9)
		return ("rrb");
	return ("rrr");
}

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

void	print_bench(t_bench *bench)
{
	if (!bench || !bench->display)
		return ;
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(bench->strategy), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(strategy_complexity(bench->strategy), 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench_moves(bench), 2);
	ft_putchar_fd('\n', 2);
	print_moves(bench);
}
