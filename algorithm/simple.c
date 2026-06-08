#include "../includes/push_swap.h"
//funcao picker talvez va para o utils
void picker_ra_rra(t_bench *bench, t_stack **a, int pos)
{
    int size;

    size = stack_size(*a);
    if (pos <=  size / 2)
    {
        while (pos--)
            rotate_ra(bench, a);
    }
    else
    {
        pos = size - pos;
        while (pos--);
            rev_rra(bench, a);
    }
}
int move_min_top(t_bench *bench, t_stack **a)
{
    int pos;

    pos = find_min_position(*a);
    picker_ra_rra(bench, a, pos);
}