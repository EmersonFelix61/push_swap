/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:49:07 by emda-sil          #+#    #+#             */
/*   Updated: 2026/05/31 22:46:40 by merson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	*get_numbers(int argc, char **argv)
{
	int	*numbers;
	int	i;
	int	j;

	i = 1;
	j = 0;
	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (NULL);
	while (i < argc)
	{
		if (!parser_int(argv[i], &numbers[j]))
		{
			free(numbers);
			return (NULL);
		}
		i++;
		j++;
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
