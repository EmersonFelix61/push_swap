/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 12:27:42 by emda-sil          #+#    #+#             */
/*   Updated: 2026/05/01 12:42:08 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*castd;
	unsigned char	*casts;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	castd = (unsigned char *)dest;
	casts = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		castd[i] = casts[i];
		i++;
	}
	return (dest);
}
