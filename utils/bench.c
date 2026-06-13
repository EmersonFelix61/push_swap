#include "../includes/push_swap.h"

int	bench_moves(t_bench *bench, t_stack **a)
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
		return ("O(\033[3mn\033[0m²)");
	if (strategy == STRAT_MEDIUM)
		return ("O(\033[3mn\033[0m√2\033[3mn\033[0m)");
	if (strategy == STRAT_COMPLEX)
		return ("O(\033[3mn\033[0mlog\033[3mn\033[0m)");
	else
		return ("Adaptive");
}
