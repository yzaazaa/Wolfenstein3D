/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:24:38 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/06 19:41:56 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_wall(t_datas *game, int *i)
{
	if (game->side == 0 && game->x_raydir > 0)
		game->image.pixels[(*i)++ * game->screen_w + game->x] = game->textures.south[game->texY * TAIL_SIZE + game->texX];
	if (game->side == 0 && game->x_raydir <= 0)
		game->image.pixels[(*i)++ * game->screen_w + game->x] = game->textures.north[game->texY * TAIL_SIZE + game->texX];
	if (game->side == 1 && game->y_raydir > 0)
		game->image.pixels[(*i)++ * game->screen_w + game->x] = game->textures.east[game->texY * TAIL_SIZE + game->texX];
	if (game->side == 1 && game->y_raydir <= 0)
		game->image.pixels[(*i)++ * game->screen_w + game->x] = game->textures.west[game->texY * TAIL_SIZE + game->texX];
}

static void	draw_floor_ceiling(t_datas *game)
{
	int	i;

	if (game->side == 0)
		game->wallX = game->pos_y + game->perp_dist_wall * game->y_raydir;
	else
		game->wallX = game->pos_x + game->perp_dist_wall * game->x_raydir;
	game->wallX -= floor(game->wallX);
	game->texX = (game->wallX * TAIL_SIZE);
	if ((game->side == 0 && game->x_raydir > 0) || (game->side == 1 && game->x_raydir < 0))
		game->texX = TAIL_SIZE - game->texX - 1;
	i = 0;
	while (i < game->draw_start)
		game->image.pixels[i++ * game->screen_w + game->x] = \
		game->map->ceilling_color;
	while (i < game->draw_end)
	{
		game->texY = ((i - (game->screen_h / 2 - game->line_height / 2)) * TAIL_SIZE) / (game->line_height + 0.5);
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
