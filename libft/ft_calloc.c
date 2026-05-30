/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:47:38 by emda-sil          #+#    #+#             */
/*   Updated: 2026/05/12 12:35:21 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	alloc;
	void	*str;

	if (size != 0 && (SIZE_MAX / size < nmemb))
		return (NULL);
	alloc = nmemb * size;
	if (alloc == 0)
		str = malloc(0);
	else
		str = malloc(alloc);
	if (!str)
		return (NULL);
	ft_bzero(str, alloc);
	return (str);
}
