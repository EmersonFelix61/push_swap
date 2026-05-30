/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:29:36 by emda-sil          #+#    #+#             */
/*   Updated: 2026/05/12 10:29:55 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newe)
{
	t_list	*last;

	if (!lst || !newe)
		return ;
	if (!*lst)
		*lst = newe;
	else
	{
		last = ft_lstlast(*lst);
		last->next = newe;
	}
}
