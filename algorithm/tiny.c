#include "../includes/push_swap.h"

void	sort_two(t_bench *bench, t_stack **a)
{
	if (stack_size(*a) == 2)
    {
        if ((*a)->value > (*a)->next->value)
            swap_sa(bench, a);
    }
}

void	sort_three(t_bench *bench, t_stack **a)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = (*a)->value;
	a2 = (*a)->next->value;
	a3 = (*a)->next->next->value;
	if (a1 > a3 && a3 > a2)
		rev_rra(bench, a);
	else if (a2 > a1 && a1 > a3)
		rotate_ra(bench, a);
	else if (a2 > a3)
		swap_sa(bench, a);
	if ((*a)->value > (*a)->next->value)
		swap_sa(bench, a);
}