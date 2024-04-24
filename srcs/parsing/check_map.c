/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:08:12 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/21 13:31:44 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

// Function that checks if the .cub file is in the right format

static void	reset(char **str, t_node *cur, char **prv_line, char **next_line)
{
	*str = cur->data;
	if (cur->prev)
		*prv_line = cur->prev->data;
	if (cur->next)
		*next_line = cur->next->data;
}

static void	check_player_spawn(t_map *map, char *line, int i)
{
	if (map->spawn_orientation == 0 && is_player_spawn(line[i]))
	{
		map->spawn_orientation = line[i];
		map->pos_x = i;
	}
	else if (is_player_spawn(line[i]))
		puterr(MANY_PLAYERS);
}

static void	check_line(t_map *map, char *line, char *next_line, char *prev_line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if ((line[i] == '0' || is_player_spawn(line[i]))
			&& (i == 0 || line[i - 1] == ' '))
			puterr(LEFT_EDGE);
		else if ((line[i] == '0' || is_player_spawn(line[i]))
			&& (!line[i + 1] || line[i + 1] == ' '))
			puterr(RIGHT_EDGE);
		else if ((line[i] == '0' || is_player_spawn(line[i]))
			&& (!next_line || next_line[i] == ' '))
			puterr(BOTTOM_EDGE);
		else if ((line[i] == '0' || is_player_spawn(line[i]))
			&& (!prev_line || prev_line[i] == ' '))
			puterr(TOP_EDGE);
		if (line[i] != '0' && line[i] != '1' && line[i] != ' '
			&& !is_player_spawn(line[i]))
			puterr(CHAR_UNEXPECTED);
		check_player_spawn(map, line, i);
	}
}

static void	update_args(t_node **current, char **next, char **prev)
{
	*current = (*current)->next;
	*next = NULL;
	*prev = NULL;
}

void	check_map(t_map *map)
{
	t_node	*current;
	char	*current_line;
	char	*previous_line;
	char	*next_line;
	int		line_pos;

	current = map->map_content->head;
	previous_line = NULL;
	next_line = NULL;
	line_pos = 0;
	while (current)
	{
		reset(&current_line, current, &previous_line, &next_line);
		if (is_empty_line(current_line))
			puterr(EMPTY_LINE_IN_MAP);
		check_line(map, current_line, next_line, previous_line);
		if (map->pos_x != -1 && map->pos_y == -1)
			map->pos_y = line_pos;
		update_args(&current, &next_line, &previous_line);
		line_pos++;
	}
	map->max_y = line_pos - 1;
	map->max_x = len_biggest_str(map->map_content);
	if (!map->spawn_orientation)
		puterr(NO_PLAYER);
}
