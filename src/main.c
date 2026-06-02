#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char		**tokens;
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
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
}
