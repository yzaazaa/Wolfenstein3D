/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:24:38 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/09 21:20:23 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_wall(t_datas *game, int *i)
{
	if (game->side == 0 && game->x_raydir > 0)
	game->image.pixels[(*i)++ * game->screen_w + game->x] = game->textures.south[game->texY * TEX_SIZE + game->texX];
	else if (game->side == 0 && game->x_raydir <= 0)
		game->image.pixels[(*i)++ * game->screen_w + game->x] = game->textures.north[game->texY * TEX_SIZE + game->texX];
	else if (game->side == 1 && game->y_raydir > 0)
		game->image.pixels[(*i)++ * game->screen_w + game->x] = game->textures.east[game->texY * TEX_SIZE + game->texX];
	else if (game->side == 1 && game->y_raydir <= 0)
		game->image.pixels[(*i)++ * game->screen_w + game->x] = game->textures.west[game->texY * TEX_SIZE + game->texX];
}

static void	draw_floor_ceiling(t_datas *game)
{
	int	i;

	i = 0;
	while (i < game->draw_start)
		game->image.pixels[i++ * game->screen_w + game->x] = \
		game->map->ceilling_color;
	if (!game->side)
		game->wallX = game->pos_y + game->perp_dist_wall * game->y_raydir;
	else
		game->wallX = game->pos_x + game->perp_dist_wall * game->x_raydir;
	game->wallX -= floor(game->wallX);
	game->texX = game->wallX * (double)TEX_SIZE;
	if ((!game->side && game->x_raydir > 0) || (game->side && game->y_raydir < 0))
		game->texX = TEX_SIZE - game->texX - 1;
	game->step = 1.0 * TEX_SIZE / game->line_height;
	game->texPos = (game->draw_start - game->screen_h / 2 + game->line_height / 2) * game->step;
	while (i < game->draw_end)
	{
		game->texY = (int)game->texPos & (TEX_SIZE - 1);
		game->texPos += game->step;
		draw_wall(game, &i);
	}
	while (i < game->screen_h)
		game->image.pixels[i++ * game->screen_w + game->x] = \
		game->map->floor_color;
}

void	drawing(t_datas *game)
{
	while (game->x < game->screen_w)
	{
		init_ray_distance(game);
		raycasting(game);
		calc_wall_height(game);
		draw_floor_ceiling(game);
		game->x++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.ptr, 0, 0);
}
