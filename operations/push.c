#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src || !dst)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	push_pa(t_bench *bench, t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
		++bench->moves[pa];
}

void	push_pb(t_bench *bench, t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
		++bench->moves[pb];
}
