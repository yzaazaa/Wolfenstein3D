/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:24:38 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/29 17:46:53 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int rgb_to_int(int color)
{
    int r = (color >> 16) & 0xFF;
    int g = (color >> 8) & 0xFF;
    int b = color & 0xFF;
    
    return ((r << 16) | (g << 8) | b);
}

void	draw_floor_ceiling(t_datas *game)
{
	int	i;

	i = -1;
	while (++i < game->draw_start)
		game->image.pixels[i * game->screen_w + game->x] = \
		rgb_to_int(game->map.ceilling_color);
	i = game->draw_end;
	while (++i < game->screen_h)
		game->image.pixels[i * game->screen_w + game->x] = \
		rgb_to_int(game->map.floor_color);
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
