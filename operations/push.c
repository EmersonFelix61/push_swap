#include "../includes/push_swap.h"
//pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
//pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. 
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
	if (!b || !*b || !a)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
	if (bench != NULL)
		++bench->moves[pa];
}

void	push_pb(t_bench *bench, t_stack **a, t_stack **b)
{
	if (!a || !*a || !b)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
	if (bench != NULL)
		++bench->moves[pb];
}
