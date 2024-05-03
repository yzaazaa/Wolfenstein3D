/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:32:12 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/03 21:38:38 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void init_game(t_datas *game)
{
	game->map = NULL;
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
	if (game->map->spawn_orientation == 'E')
	{
		game->x_dir = 0.0;
		game->y_dir = 1.0;
		game->x_plane = 0.66;
		game->y_plane = 0.0;
	}
	if (game->map->spawn_orientation == 'W')
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
	game->pos_x = game->map->player.x;
	game->pos_y = game->map->player.y;
	if (game->map->spawn_orientation == 'N')
	{
		game->x_dir = -1.0;
		game->y_dir = 0.0;
		game->x_plane = 0.0;
		game->y_plane = 0.66;
	}
	if (game->map->spawn_orientation == 'S')
	{
		game->x_dir = 1.0;
		game->y_dir = 0.0;
		game->x_plane = 0.0;
		game->y_plane = -0.66;
	}
	_start_game(game);
}