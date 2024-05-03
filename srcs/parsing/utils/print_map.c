/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:50:36 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/03 21:32:14 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//	Function that prints map content

void	print_map_content(t_map *map)
{
	if (map->floor_color)
		printf("floor color: %d,%d,%d\n", get_r(map->floor_color), get_g(map->floor_color), get_b(map->floor_color));
	if (map->ceilling_color)
		printf("ceiling color: %d,%d,%d\n", get_r(map->ceilling_color), get_g(map->ceilling_color), get_b(map->ceilling_color));
	if (map->north_texture)
		printf("north texture: %s\n", map->north_texture);
	if (map->west_texture)
		printf("west texture: %s\n", map->west_texture);
	if (map->south_texture)
		printf("south texture: %s\n", map->south_texture);
	if (map->east_texture)
		printf("east texture: %s\n", map->east_texture);
	if (map->player.x != -1)
		printf("player x position: %d\n", map->player.x);
	if (map->player.y != -1)
		printf("player y position: %d\n", map->player.y);
	if (map->spawn_orientation != -1)
		printf("spawn oritentation: %c\n", map->spawn_orientation);
	if (map->col != -1)
		printf("cols: %d\n", map->col);
	if (map->row != -1)
		printf("rows: %d\n", map->row);
	if (map->map2d)
	{	
		printf("map :\n");
		print_array(map->map2d);
	}
}
