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

void    picker_rb_rrb(t_bench *bench, t_stack **b, int pos)
{
    int size;

    if (!b || !*b)
        return ;
    if (pos == 0)
        return ;
    size = stack_size(*b);
    if (pos <=  size / 2)
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
}

int find_insert_pos(t_stack *a, int value)
{
    int     pos;
    t_stack *cur;
    t_stack *next;

    pos = 0;
    cur = a;
    while (cur)
    {
        next = cur->next;
        if (!next)
            next = a;
        if (value > cur->value && value < next->value)
            return (pos + 1);
        if (cur->value > next->value
            && (value > cur->value || value < next->value))
            return (pos + 1);
        cur = cur->next;
        pos++;
    }
    return (0);
}
void    move_min_top(t_bench *bench, t_stack **a)
{
    int pos;

    pos = find_min_position(*a);
    picker_ra_rra(bench, a, pos);
}

static int  cost(int pos, int size)
{
    if (pos <= size / 2)
        return (pos);
    return (size - pos);
}

static void find_best(t_stack *a, t_stack *b, int *best_pa, int *best_pb)
{
    t_stack *cur;
    int     pb;
    int     pa;
    int     sa;
    int     sb;
    int     c;
    int     best;

    sa = stack_size(a);
    sb = stack_size(b);
    best = INT_MAX;
    pb = 0;
    cur = b;
    while (cur)
    {
        pa = find_insert_pos(a, cur->value);
        if ((pa <= sa / 2) == (pb <= sb / 2))
            c = (cost(pa, sa) > cost(pb, sb)) ? cost(pa, sa) : cost(pb, sb);
        else
            c = cost(pa, sa) + cost(pb, sb);
        if (c < best)
        {
            best = c;
            *best_pa = pa;
            *best_pb = pb;
        }
        cur = cur->next;
        pb++;
    }
}

void    simple_sort(t_bench *bench, t_stack **a, t_stack **b)
{
    int pa;
    int pb;

    if (!a || !*a || is_sorted(*a))
        return ;
    while (stack_size(*a) > 3)
        push_pb(bench, a, b);
    sort_three(bench, a);
    while (*b)
    {
        find_best(*a, *b, &pa, &pb);
        picker_ra_rra(bench, a, pa);
        picker_rb_rrb(bench, b, pb);
        push_pa(bench, a, b);
    }
    move_min_top(bench, a);
}