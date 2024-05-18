/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:17:42 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:15:12 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Function that removes new_line at the end of the line

static char	*remove_new_line(char *line, t_map *map)
{
	char	*ret;
	int		i;

	if (line[ft_strlen(line) - 1] != '\n')
	{
		ret = ft_strdup(line);
		if (!ret)
			puterr(MALLOC_ERR, NULL, map);
		return (ret);
	}
	ret = malloc(ft_strlen(line));
	if (!ret)
		puterr(MALLOC_ERR, NULL, map);
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

t_list	*get_raw_map(char *cub_file, t_map *map)
{
	int		cub_fd;
	char	*line;
	t_list	*raw_map;

	raw_map = NULL;
	cub_fd = open(cub_file, O_RDONLY);
	if (cub_fd == -1)
		puterr(OPEN_ERR, NULL, map);
	line = get_next_line(cub_fd);
	while (line)
	{
		add_back_lst(&raw_map, (void *)remove_new_line(line, map), map);
		free(line);
		line = get_next_line(cub_fd);
	}
	close(cub_fd);
	return (raw_map);
}
