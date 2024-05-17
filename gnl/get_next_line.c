/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:44:53 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/03 02:37:34 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin_n(NULL, buffer);
	if (check_str(buffer))
		return (line);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(line), NULL);
		if (i == 0 && line[0] == '\0')
			return (free(line), NULL);
		line = ft_strjoin_n(line, buffer);
		if (check_str(buffer))
			return (line);
	}
	return (line);
}
