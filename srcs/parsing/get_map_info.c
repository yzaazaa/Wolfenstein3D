/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:29:13 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/03 21:24:25 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Function that checks if the first line is full of
// 1s, 0s, player_spawn or spaces

static int	check_first_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '1' || line[i] == '0'
		|| is_player_spawn(line[i]))
		i++;
	if (line[i])
		return (0);
	return (1);
}

// Function that gets textures and colors

static int	check_line(t_map *map, char *line)
{
	if (map->floor_color == -1 && line[0] == 'F' && line[1] == ' ')
		map->floor_color = get_color(line);
	else if (map->ceilling_color == -1 && line[0] == 'C' && line[1] == ' ')
		map->ceilling_color = get_color(line);
	else if (map->north_texture == NULL
		&& line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		map->north_texture = get_texture(map, line);
	else if (map->west_texture == NULL
		&& line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		map->west_texture = get_texture(map, line);
	else if (map->south_texture == NULL
		&& line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		map->south_texture = get_texture(map, line);
	else if (map->east_texture == NULL
		&& line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		map->east_texture = get_texture(map, line);
	else if (map->ceilling_color != -1 && map->floor_color != -1
		&& map->east_texture && map->north_texture
		&& map->south_texture && map->west_texture && check_first_line(line))
		return (0);
	else
		puterr(LINE_UNEXPECTED);
	return (1);
}

static int	check_all_set(t_map *map, char *str, t_node *head)
{
	if (map->ceilling_color != -1 && map->floor_color != -1
		&& map->east_texture && map->north_texture
		&& map->south_texture && map->west_texture && check_first_line(str))
		return (1);
	head->data = ft_strtrim_free(str, " \t");
	return (0);
}

void	get_map_info(t_map *map, t_list *raw_map)
{
	t_node	*head;
	char	*line;
	char	*tmp;

	if (!raw_map)
		puterr(CUB_ERR);
	head = raw_map->head;
	while (head)
	{
		tmp = head->data;
		if (is_empty_line(tmp))
		{
			head = head->next;
			if (head)
				remove_node_list(raw_map, head->prev);
			continue ;
		}
		if (check_all_set(map, tmp, head))
			break ;
		line = head->data;
		if (!check_line(map, line))
			break ;
		head = head->next;
	}
}
