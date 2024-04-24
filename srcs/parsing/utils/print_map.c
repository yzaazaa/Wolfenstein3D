/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:50:36 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/21 13:22:53 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parsing.h"

//	Function that prints map content

void	print_map_content(t_map *map)
{
	if (map->floor_color)
		printf("floor color: %d,%d,%d\n", get_r(map->floor_color), get_g(map->floor_color), get_b(map->floor_color));
	if (map->ceiling_color)
		printf("ceiling color: %d,%d,%d\n", get_r(map->ceiling_color), get_g(map->ceiling_color), get_b(map->ceiling_color));
	if (map->north_texture)
		printf("north texture: %s\n", map->north_texture);
	if (map->west_texture)
		printf("west texture: %s\n", map->west_texture);
	if (map->south_texture)
		printf("south texture: %s\n", map->south_texture);
	if (map->east_texture)
		printf("east texture: %s\n", map->east_texture);
	if (map->pos_x != -1)
		printf("player x position: %d\n", map->pos_x);
	if (map->pos_y != -1)
		printf("player y position: %d\n", map->pos_y);
	if (map->max_x != -1)
		printf("max x: %d\n", map->max_x);
	if (map->max_y != -1)
		printf("max y: %d\n", map->max_y);
	if (map->map_content)
	{	
		printf("map :\n");
		print_list(map->map_content);
	}
}
