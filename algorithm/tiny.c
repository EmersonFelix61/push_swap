#include "../includes/push_swap.h"

void	sort_two(t_bench *bench, t_stack **a)
{
	if (!a || !*a || stack_size(*a) != 2)
		return ;
	if ((*a)->value > (*a)->next->value)
		swap_sa(bench, a);
}

void	sort_three(t_bench *bench, t_stack **a)
{
	int	a1;
	int	a2;
	int	a3;

	if (!a || !*a || stack_size(*a) != 3)
		return ;
	a1 = (*a)->value;
	a2 = (*a)->next->value;
	a3 = (*a)->next->next->value;
	if (a1 > a2 && a2 < a3 && a1 < a3)
		swap_sa(bench, a);
	else if (a1 > a2 && a2 > a3)
	{
		swap_sa(bench, a);
		rev_rra(bench, a);
	}
	else if (a1 > a2 && a2 < a3 && a1 > a3)
		rotate_ra(bench, a);
	else if (a1 < a2 && a2 > a3 && a1 < a3)
	{
		swap_sa(bench, a);
		rotate_ra(bench, a);
	}
	else if (a1 < a2 && a2 > a3 && a1 > a3)
		rev_rra(bench, a);
}

void	sort_four(t_bench *bench, t_stack **a, t_stack **b)
{
	int	pos;

	if (!a || !*a || !b || stack_size(*a) != 4)
		return ;
	pos = find_min_position(*a);
	picker_ra_rra(bench, a, pos);
	push_pb(bench, a, b);
	sort_three(bench, a);
	push_pa(bench, a, b);
}

void	sort_five(t_bench *bench, t_stack **a, t_stack **b)
{
	int	pos;

	if (!a || !*a || !b || stack_size(*a) != 5)
		return ;
	pos = find_min_position(*a);
	picker_ra_rra(bench, a, pos);
	push_pb(bench, a, b);
	pos = find_min_position(*a);
	picker_ra_rra(bench, a, pos);
	push_pb(bench, a, b);
	sort_three(bench, a);
	push_pa(bench, a, b);
	push_pa(bench, a, b);
}