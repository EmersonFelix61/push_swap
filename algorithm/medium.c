#include "../includes/push_swap.h"

static int	get_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	if (size > 100)
		chunk *= 2;
	return (chunk);
}

static void	push_b(t_bench *bench, t_stack **a, t_stack **b, int *arr)
{
	int	size;
	int	chunk;
	int	limit;
	int	pushed;

	size = stack_size(*a);
	chunk = get_chunk_size(size);
	limit = chunk - 1;
	pushed = 0;
	while (*a)
	{
		if (limit >= size)
			limit = size - 1;
		if ((*a)->value <= arr[limit])
		{
			push_pb(bench, a, b);
			pushed++;
			if (pushed > limit)
				limit += chunk;
		}
		else
			rotate_ra(bench, a);
	}
}

static void	push_a(t_bench *bench, t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	while (*b)
	{
		pos = find_max_position(*b);
		size = stack_size(*b);
		if (pos <= size / 2)
		{
			while (pos--)
				rotate_rb(bench, b);
		}
		else
		{
			pos = size - pos;
			while (pos--)
				rev_rrb(bench, b);
		}
		push_pa(bench, a, b);
	}
}

void	medium_sort(t_bench *bench, t_stack **a, t_stack **b)
{
	int	*array;

	if (!a || !*a || is_sorted(*a))
		return ;
	array = get_array(*a);
	if (!array)
		return ;
	push_b(bench, a, b, array);
	free(array);
	push_a(bench, a, b);
}
