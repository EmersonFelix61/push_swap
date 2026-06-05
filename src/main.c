#include "../includes/push_swap.h"
/*
int	main(int argc, char **argv)
{
	char		**tokens;
	t_stack		*a;
	t_stack		*b;
	t_bench		bench;
	t_config	config;

	a = NULL;
	b = NULL;
	init_config(&config);
	if (argc == 1)
		return (0);
	tokens = get_tokens(argc, argv);
	if (!tokens)
	{
		free_tokens(tokens);
		print_error();
		return (0);
	}
	a = stack_builder(tokens);
	free_tokens(tokens);
	if (!a)
	{
		print_error();
		return (0);
	}
	//por completar...
	stack_free(&a);
	stack_free(&b);
	return (0);
}
*/
//teste swap push ...
void    print_stack(char *name, t_stack *stack)
{
    ft_printf("%s: ", name);
    while (stack)
    {
        ft_printf("%d ", stack->value);
        stack = stack->next;
    }
    ft_printf("\n");
}

int main(void)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    add_back(&a, new_stack(3));
    add_back(&a, new_stack(2));
    add_back(&a, new_stack(1));

    print_stack("A antes", a);
    print_stack("B antes", b);

    swap_sa(NULL, &a);
    print_stack("A depois sa", a);

    rotate_ra(NULL, &a);
    print_stack("A depois ra", a);

    rev_rra(NULL, &a);
    print_stack("A depois rra", a);

    push_pb(NULL, &a, &b);
    print_stack("A depois pb", a);
    print_stack("B depois pb", b);

	
    stack_free(&a);
    stack_free(&b);
    return (0);
}
