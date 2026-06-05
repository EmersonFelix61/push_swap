#include "../includes/push_swap.h"

void	init_config(t_config *config, t_bench *bench)
{
	config->strategy = STRAT_ADAPTIVE;
	config->numbers_count = 0;
	config->bench = bench;
}

int	set_bench(char *token, t_config *config)
{
	if (ft_strncmp(token, "--bench", 8) != 0)
		return (0);
	if (config->bench->display)
		return (-1);
	config->bench->display = 1;
	return (1);
}

int	set_strategy(char *token, t_config *config, int *strategy_tester)
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
			config->strategy = STRAT_SIMPLE;
		else if (ft_strncmp(token, "--medium", 9) == 0)
			config->strategy = STRAT_MEDIUM;
		else if (ft_strncmp(token, "--complex", 10) == 0)
			config->strategy = STRAT_COMPLEX;
		else
			config->strategy = STRAT_ADAPTIVE;
		return (1);
	}
	if (token[0] == '-' && token[1] == '-')
		return (-1);
	return (0);
}

static int	set_flags(char *token, t_config *config, int *strategy_tester)
{
	int	flag_found;

	flag_found = set_bench(token, config);
	if (flag_found == -1)
		return (-1);
	if (flag_found == 1)
		return (1);
	flag_found = set_strategy(token, config, strategy_tester);
	if (flag_found == -1)
		return (-1);
	if (flag_found == 1)
		return (1);
	return (0);
}

int	parser_flags(char **tokens, t_config *config)
{
	int	i;
	int	flag_found;
	int	strategy_tester;

	i = 0;
	strategy_tester = 0;
	while (tokens[i])
	{
		flag_found = set_flags(tokens[i], config, &strategy_tester);
		if (flag_found == -1)
			return (0);
		if (flag_found == 0)
			config->numbers_count++;
		i++;
	}
	if (config->numbers_count == 0)
		return (0);
	return (1);
}
