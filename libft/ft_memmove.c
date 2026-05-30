/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 12:44:39 by emda-sil          #+#    #+#             */
/*   Updated: 2026/05/01 13:40:22 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*casts;
	unsigned char		*castd;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	castd = (unsigned char *)dest;
	casts = (unsigned char *)src;
	if (castd < casts)
	{
		i = 0;
		while (i < n)
		{
			castd[i] = casts[i];
			i++;
		}
		return (dest);
	}
	i = n;
	while (i > 0)
	{
		i--;
		castd[i] = casts[i];
	}
	return (dest);
}
