/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:02:57 by emda-sil          #+#    #+#             */
/*   Updated: 2026/04/30 11:07:32 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	len;

	if (!*little)
		return ((char *)big);
	if (!*big)
		return (NULL);
	i = 0;
	len = ft_strlen(little);
	while ((len + i <= n) && big[i])
	{
		if (ft_strncmp(&big[i], little, len) == 0)
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
