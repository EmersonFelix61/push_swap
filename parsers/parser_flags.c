#include "../includes/push_swap.h"

void	init_config(t_config *config)
{
	config->strategy = STRAT_ADAPTIVE;
	config->bench = 0;
	config->numbers_count = 0;
}

int	set_bench(char *token, t_config *config, t_bench *bench)
{
	if (ft_strncmp(token, "--bench", 8) != 0)
		return (0);
	if (config->bench)
		return (-1);
	init_bench(bench);
	config->bench = bench;
	return (1);
}

int	set_strategy(char *token, t_config *config, int *strategy_found)
{
	if (ft_strncmp(token, "--simple", 9) == 0
		|| ft_strncmp(token, "--medium", 9) == 0
		|| ft_strncmp(token, "--complex", 10) == 0
		|| ft_strncmp(token, "--adaptive", 11) == 0)
	{
		if (*strategy_found)
			return (-1);
		*strategy_found = 1;
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
