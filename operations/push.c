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

void	pa(t_config *config, t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
	++config->bench->moves[3];
}

void	pb(t_config *config, t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
	++config->bench->moves[4];
}
