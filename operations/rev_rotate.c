#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp1 = stack_last(*stack);
	tmp2 = stack_before_last(*stack);
	tmp2->next = NULL;
	tmp1->next = *stack;
	*stack = tmp1;
}

void	rev_rra(t_config *config, t_stack **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
	if (config && config->bench)
		++config->bench->moves[rra];
}

void	rev_rrb(t_config *config, t_stack **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
	if (config && config->bench)
		++config->bench->moves[rrb];
}

void	rev_rrr(t_config *config, t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
	if (config && config->bench)
		++config->bench->moves[rrr];
}
