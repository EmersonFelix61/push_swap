#include "../includes/push_swap.h"

int	parser_numbers(char *arg)
{
	int	i;

	i = 0;
	if (!arg || arg[0] == '\0')
		return (0);
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parser_range(char *arg)
{
	int			i;
	int			sign;
	const char	*limit;

	i = 0;
	sign = 1;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	while (arg[i] == '0')
		i++;
	if (ft_strlen(&arg[i]) < 10)
		return (1);
	if (ft_strlen(&arg[i]) > 10)
		return (0);
	if (sign == -1)
		limit = "2147483648";
	else
		limit = "2147483647";
	if (ft_strncmp(&arg[i], limit, 10) > 0)
		return (0);
	return (1);
}

int	parser_int(char *arg, int *number)
{
	if (!parser_numbers(arg))
		return (0);
	if (!parser_range(arg))
		return (0);
	*number = (int)ft_atoi(arg);
	return (1);
}

int	*get_numbers(char **tokens, int numbers_count)
{
	int	*numbers;
	int	i;
	int	j;

	numbers = malloc(sizeof(int) * numbers_count);
	if (!numbers)
		return (NULL);
	i = 0;
	j = 0;
	while (tokens[i])
	{
		if (ft_strncmp(tokens[i], "--bench", 8) == 0
			|| ft_strncmp(tokens[i], "--simple", 9) == 0
			|| ft_strncmp(tokens[i], "--medium", 9) == 0
			|| ft_strncmp(tokens[i], "--complex", 10) == 0
			|| ft_strncmp(tokens[i], "--adaptive", 11) == 0)
		{
			i++;
			continue ;
		}
		if (!parser_int(tokens[i], &numbers[j++]))
			return (free(numbers), NULL);
		i++;
	}
	return (numbers);
}

int	is_duplicate(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
