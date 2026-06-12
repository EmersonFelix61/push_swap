#include "../includes/push_swap.h"

double	ft_disorder(t_stack *stack)
{
	double	mistakes;
	double	total_pairs;
	t_stack	*start;
	t_stack	*next_start;

	mistakes = 0;
	total_pairs = 0;
	start = stack;
	if (!stack || !stack->next)
		return (0);
	while (start)
	{
		next_start = start->next;
		while (next_start)
		{
			++total_pairs;
			if (start->value > next_start->value)
				++mistakes;
			next_start = next_start->next;
		}
		start = start->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}

void	adaptive_sort(t_bench *bench, t_stack **a, t_stack **b)
{
	double	disorder;

	if (!a || !*a || !b || is_sorted(*a))
		return ;
	disorder = ft_disorder(*a);
	bench->disorder = disorder;
	if (disorder < 0.2)
		simple_sort(bench, a, b);
	else if (disorder < 0.5)
		medium_sort(bench, a, b);
	//else
		//o complext vem aqui.
}
