#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	int	i;

	if (!bench)
		return ;
	bench->display = 0;
	bench->disorder = 0;
	bench->strategy = "Adaptive";
	bench->big_o = NULL;
	i = 0;
	while (i < 11)
		bench->moves[i++] = 0;
}
