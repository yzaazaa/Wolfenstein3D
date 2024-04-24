/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:17:42 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/24 17:30:27 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Function that removes new_line at the end of the line

static char	*remove_new_line(char *line)
{
	char	*ret;
	int		i;

	if (line[ft_strlen(line) - 1] != '\n')
		return (ft_strdup(line));
	ret = malloc(ft_strlen(line));
	if (!ret)
		puterr(MALLOC_ERR);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// Function that reads the file and return it as a linked list
// where each node is a line

t_list	*get_raw_map(char *cub_file)
{
	int		cub_fd;
	char	*line;
	t_list	*raw_map;

	raw_map = NULL;
	cub_fd = open(cub_file, O_RDONLY);
	// if (cub_fd == -1)
		puterr(OPEN_ERR);
	line = get_next_line(cub_fd);
	while (line)
	{
		add_back_lst(&raw_map, (void *)remove_new_line(line));
		free(line);
		line = get_next_line(cub_fd);
	}
	close(cub_fd);
	return (raw_map);
}
