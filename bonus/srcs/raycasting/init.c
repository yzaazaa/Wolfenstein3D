/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:32:12 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/17 21:51:16 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_game(t_datas *game)
{
	game->map = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		puterr(MLX_ERR, game, NULL);
	game->screen_h = SCREEN_H;
	game->screen_w = SCREEN_W;
	game->x = 0;
	ft_new_window(game);
	game->image.ptr = mlx_new_image(game->mlx, game->screen_w, game->screen_h);
	if (!game->image.ptr)
		puterr(MLX_IMAGE_ERR, game, NULL);
	game->image.pixels = (int *)mlx_get_data_addr(game->image.ptr,
			&(game->image.bpp),
			&(game->image.line_len),
			&(game->image.endian));
	if (!game->image.pixels)
		puterr(MLX_IMAGE_DATA_ERR, game, NULL);
}

void	_start_game(t_datas *game)
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

void	start_game(t_datas *game)
{
	game->rote_angle = 0.1;
	game->movespeed = 0.1;
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
