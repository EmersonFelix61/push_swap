#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	*tokens;

	if (argc <= 1)
		return (print_error(), 0);
	tokens = get_tokens(argc, argv);
	if (!tokens)
		return (print_error(), 0);
}
