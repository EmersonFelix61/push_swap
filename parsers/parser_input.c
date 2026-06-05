#include "../includes/push_swap.h"

int	parser(int argc, char **argv, int **numbers, t_config *config, t_bench *bench)
{
	char	**tokens;

	if (argc == 1)
		return (0);
	tokens = get_tokens(argc, argv);
	if (!tokens)
		return (-1);
	init_bench(bench);
	init_config(config, bench);
	if (!parser_flags(tokens, config))
		return (free_tokens(tokens), -1);
	*numbers = get_numbers(tokens, config->numbers_count);
	if (!*numbers)
		return (free_tokens(tokens), -1);
	if (is_duplicate(*numbers, config->numbers_count))
	{
		free_tokens(tokens);
		free(*numbers);
		*numbers = NULL;
		return (-1);
	}
	free_tokens(tokens);
	return (1);
}
