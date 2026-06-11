#include "../includes/push_swap.h"

int get_pivot(t_stack *stack)
{
    int *array;
    int pivot;
    int size;

    size = stack_size(stack);
    array = stack_to_array(stack);
    if (!array)
        return(0);
    sort_array(array, size);
    pivot = array[size / 2];
    free (array);
    return (pivot);
}

int partition_a(t_bench *bench, t_stack **a, t_stack **b, int size)
{
    int i;
    int pivot;
    int count;

    pivot = get_pivot(*a);
    i = 0;
    count = 0;
    while (i < size)
    {
        if ((*a)->value < pivot)
            rotate_ra(bench, a);
        else
        {
            push_pb(bench, a, b);
            ++count;
        }
        i++;
    }
    return (count);
}