/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_apply_instruction_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:48:53 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/16 13:32:17 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	checker_apply_instruction(char *instruction, t_stack **a, t_stack **b)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		return (swap(a), swap(b), 1);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		return (rotate(a), rotate(b), 1);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		rev_rotate(a);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		rev_rotate(b);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		return (rev_rotate(a), rev_rotate(b), 1);
	else
		return (0);
	return (1);
}
