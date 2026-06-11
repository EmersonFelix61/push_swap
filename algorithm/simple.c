#include "../includes/push_swap.h"
//funcao picker talvez va para o utils
void    picker_ra_rra(t_bench *bench, t_stack **a, int pos)
{
    int size;

    if (!a || !*a)
        return ;
    if (pos == 0)
        return ;
    size = stack_size(*a);
    if (pos <=  size / 2)
    {
        while (pos--)
            rotate_ra(bench, a);
    }
    else
    {
        pos = size - pos;
        while (pos--)
            rev_rra(bench, a);
    }
}

void    move_max_top(t_bench *bench, t_stack **a)
{
    int pos;

    pos = find_max_position(*a);
    picker_ra_rra(bench, a, pos);
}

void    simple_sort(t_bench *bench, t_stack **a, t_stack **b)
{
    if (!a || !*a || is_sorted(*a))
        return ;
    while (*a)
    {
        move_max_top(bench, a);
        push_pb(bench, a, b);
    }
    while (*b)
        push_pa(bench, a, b);
}
