#include "../includes/push_swap.h"

int	set_strategy(t_bench *bench, char *token, int *strategy_tester)
{
	if (ft_strncmp(token, "--simple", 9) == 0
		|| ft_strncmp(token, "--medium", 9) == 0
		|| ft_strncmp(token, "--complex", 10) == 0
		|| ft_strncmp(token, "--adaptive", 11) == 0)
	{
		if (*strategy_tester)
			return (-1);
		*strategy_tester = 1;
		if (ft_strncmp(token, "--simple", 9) == 0)
			bench->strategy = STRAT_SIMPLE;
		else if (ft_strncmp(token, "--medium", 9) == 0)
			bench->strategy = STRAT_MEDIUM;
		else if (ft_strncmp(token, "--complex", 10) == 0)
			bench->strategy = STRAT_COMPLEX;
		else
			bench->strategy = STRAT_ADAPTIVE;
		return (1);
	}
	if (token[0] == '-' && token[1] == '-')
		return (-1);
	return (0);
}

static int	set_flags(char *token, t_bench *bench, int *strategy_tester)
{
	int	flag_found;

	flag_found = set_bench(bench, token);
	if (flag_found == -1)
		return (-1);
	if (flag_found == 1)
		return (1);
	flag_found = set_strategy(bench, token, strategy_tester);
	if (flag_found == -1)
		return (-1);
	if (flag_found == 1)
		return (1);
	return (0);
}

int	parser_flags(char **tokens, t_bench *bench)
{
	int	i;
	int	flag_found;
	int	strategy_tester;

	i = 0;
	strategy_tester = 0;
	while (tokens[i])
	{
		flag_found = set_flags(tokens[i], bench, &strategy_tester);
		if (flag_found == -1)
			return (0);
		if (flag_found == 0)
			bench->numbers_count++;
		i++;
	}
	if (bench->numbers_count == 0)
		return (0);
	return (1);
}
