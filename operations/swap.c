#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || ! *stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_config *config, t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
	++config->bench->moves[0];
}

void	sb(t_config *config, t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
	++config->bench->moves[1];
}

void	ss(t_config *config, t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	++config->bench->moves[2];
}
