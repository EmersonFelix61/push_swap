#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	**tokens;

	if (argc == 1)
		return (0);
	tokens = get_tokens(argc, argv);
	if (!tokens)
	{
		free_tokens(tokens);
		print_error();
		return (0);
	}
}
