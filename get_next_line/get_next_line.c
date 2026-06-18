/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raferrei <raferrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:03:54 by raferrei          #+#    #+#             */
/*   Updated: 2026/05/27 11:41:58 by raferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		rbytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rbytes = 1;
	while (!ft_strchr(str, '\n') && rbytes > 0)
	{
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes < 0)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[rbytes] = '\0';
		str = gnl_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*ft_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (ft_substr(str, 0, i));
}

static char	*ft_next(char *str)
{
	int		i;
	char	*next;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
	{
		free (str);
		return (NULL);
	}
	next = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
	free(str);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*record;
	char		*line;	

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	record = ft_read(fd, record);
	if (!record || *record == '\0')
		return (free(record), record = NULL, NULL);
	line = ft_line(record);
	record = ft_next(record);
	return (line);
}
