#include "../includes/push_swap.h"

void	move_min_top(t_bench *bench, t_stack **a)
{
	int pos;

	pos = find_min_position(*a);
	picker_ra_rra(bench, a, pos);
}