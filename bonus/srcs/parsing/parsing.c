/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:11:27 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:11:29 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

// Function that inits the map struct

static void	init_map(t_map *map)
{
	map->map_content = NULL;
	map->spawn_orientation = (char)0;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->door_texture = NULL;
	map->ceilling_color = -1;
	map->floor_color = -1;
	map->row = -1;
	map->col = -1;
	map->player.x = -1;
	map->player.y = -1;
}

static int	get_line_check(char c, char c1)
{
	if (c == 'F')
		return (1);
	else if (c == 'C')
		return (1);
	else if (c == 'N' && c1 == 'O')
		return (1);
	else if (c == 'W' && c1 == 'E')
		return (1);
	else if (c == 'S' && c1 == 'O')
		return (1);
	else if (c == 'E' && c1 == 'A')
		return (1);
	else if (c == 'D')
		return (1);
	return (0);
}

// Function that removes all info lines from the .cub file

static void	remove_info_lines(t_list *raw_map)
{
	t_node	*current;
	int		check;
	char	*line;

	current = raw_map->head;
	while (current)
	{
		check = 0;
		line = current->data;
		check = get_line_check(line[0], line[1]);
		current = current->next;
		if (check == 1 && current)
			remove_node_list(raw_map, current->prev);
	}
}

static void	trim_map(t_list *raw_map)
{
	t_node	*current;

	current = raw_map->tail;
	while (current)
	{
		if (is_empty_line((char *)current->data))
		{
			current = current->prev;
			if (current)
				remove_node_list(raw_map, current->next);
		}
		else
			break ;
	}
}

// Function that parses the map and returns a map struct

void	parse_map(t_map *map, char *cub_file)
{
	t_list	*raw_map;

	check_file_name(cub_file);
	init_map(map);
	raw_map = get_raw_map(cub_file, map);
	get_map_info(map, raw_map);
	remove_info_lines(raw_map);
	trim_map(raw_map);
	fill_spaces(raw_map, map);
	map->map_content = raw_map;
	check_map(map);
	map->map2d = list_to_array(map->map_content, map);
	free_list(&map->map_content);
}
