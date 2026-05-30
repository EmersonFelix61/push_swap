/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emda-sil <emda-sil@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:53:50 by emda-sil          #+#    #+#             */
/*   Updated: 2026/05/07 13:54:56 by emda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	i;
	size_t	j;
	size_t	sub_str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	if (s1[i] == 0)
		return (ft_strdup(""));
	j = len_s1 - 1;
	while (j > i && ft_strchr(set, s1[j]) != NULL)
		j--;
	sub_str = j - i + 1;
	return (ft_substr(s1, i, sub_str));
}
