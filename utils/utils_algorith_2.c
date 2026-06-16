/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorith_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:58:29 by emda-sil          #+#    #+#             */
/*   Updated: 2026/06/15 11:58:47 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_min_top(t_bench *bench, t_stack **a)
{
	int	pos;

	pos = find_min_position(*a);
	picker_ra_rra(bench, a, pos);
}
