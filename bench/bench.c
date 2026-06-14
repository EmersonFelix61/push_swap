
#include "../includes/push_swap.h"

void	init_bench(t_bench *bench)
{
	int	i;

	bench->strategy = STRAT_ADAPTIVE;
	bench->numbers_count = 0;
	bench->disorder = 0;
	bench->used_strategy = 0;
	bench->display = 0;
	i = 0;
	while (i < 11)
		bench->moves[i++] = 0;
}

int	set_bench(t_bench *bench, char *token)
{
	if (ft_strncmp(token, "--bench", 8) != 0)
		return (0);
	if (bench->display)
		return (-1);
	bench->display = 1;
	return (1);
}
