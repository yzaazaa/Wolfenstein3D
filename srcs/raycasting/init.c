/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:32:12 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/29 17:47:33 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void init_maps(t_map *map)
{
	map->map2d = NULL;
	map->row = -1;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->east_texture = NULL;
	map->west_texture = NULL;
	map->filename = NULL;
	map->starting_pos = '\0';
	map->ceilling_color = -1;
	map->floor_color = -1;
	map->player.x = 0;
	map->player.y = 0;
}

void init_game(t_datas *game)
{
	init_maps(&game->map);
	game->mlx = mlx_init();
	game->cub_content = NULL;
	game->screen_h = 1024;
	game->screen_w = 1024;
	game->x = 0;
	ft_new_window(game);
	game->image.ptr = mlx_new_image(game->mlx, game->screen_w, game->screen_h);
	game->image.pixels = (int *)mlx_get_data_addr(game->image.ptr, &(game->image.bpp),
												  &(game->image.line_len), &(game->image.endian));
}

void _start_game(t_datas *game)
{
	if (game->map.starting_pos == 'E')
	{
		game->x_dir = 0.0;
		game->y_dir = 1.0;
		game->x_plane = 0.66;
		game->y_plane = 0.0;
	}
	if (game->map.starting_pos == 'W')
	{
		game->x_dir = 0.0;
		game->y_dir = -1.0;
		game->x_plane = -0.66;
		game->y_plane = 0.0;
	}
}

void start_game(t_datas *game)
{
	game->rote_angle = 0.2;
	game->movespeed = 0.4;
	game->x_plane = 0.0;
	game->y_plane = 0.66;
	game->pos_x = game->map.player.x;
	game->pos_y = game->map.player.y;
	if (game->map.starting_pos == 'N')
	{
		game->x_dir = -1.0;
		game->y_dir = 0.0;
		game->x_plane = 0.0;
		game->y_plane = 0.66;
	}
	if (game->map.starting_pos == 'S')
	{
		game->x_dir = 1.0;
		game->y_dir = 0.0;
		game->x_plane = 0.0;
		game->y_plane = -0.66;
	}
	_start_game(game);
}