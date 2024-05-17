/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:24:38 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/17 16:53:34 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_wall(t_datas *game, int *i)
{
	if (game->door == 1)
		put_pixel(game, game->x,
			(*i)++, game->textures.door[game->tex_y * TEX_SIZE + game->tex_x]);
	else if (game->side == 0 && game->x_raydir > 0)
		put_pixel(game, game->x,
			(*i)++, game->textures.south[game->tex_y * TEX_SIZE + game->tex_x]);
	else if (game->side == 0 && game->x_raydir <= 0)
		put_pixel(game, game->x,
			(*i)++, game->textures.north[game->tex_y * TEX_SIZE + game->tex_x]);
	else if (game->side == 1 && game->y_raydir > 0)
		put_pixel(game, game->x,
			(*i)++, game->textures.east[game->tex_y * TEX_SIZE + game->tex_x]);
	else if (game->side == 1 && game->y_raydir <= 0)
		put_pixel(game, game->x,
			(*i)++, game->textures.west[game->tex_y * TEX_SIZE + game->tex_x]);
}

static void	draw_floor_ceiling(t_datas *game)
{
	int	i;

	i = 0;
	while (i < game->draw_start)
		put_pixel(game, game->x, i++, game->map->ceilling_color);
	if (!game->side)
		game->wallx = game->pos_y + game->perp_dist_wall * game->y_raydir;
	else
		game->wallx = game->pos_x + game->perp_dist_wall * game->x_raydir;
	game->wallx -= floor(game->wallx);
	game->tex_x = game->wallx * (double)TEX_SIZE;
	if ((!game->side && game->x_raydir > 0)
		|| (game->side && game->y_raydir < 0))
		game->tex_x = TEX_SIZE - game->tex_x - 1;
	game->step = 1.0 * TEX_SIZE / game->line_height;
	game->texpos = (game->draw_start - game->screen_h
			/ 2 + game->line_height / 2) * game->step;
	while (i < game->draw_end)
	{
		game->tex_y = (int)game->texpos & (TEX_SIZE - 1);
		game->texpos += game->step;
		draw_wall(game, &i);
	}
	while (i < game->screen_h)
		put_pixel(game, game->x, i++, game->map->floor_color);
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
}
