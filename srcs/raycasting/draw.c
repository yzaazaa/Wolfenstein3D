/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:24:38 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/27 21:11:41 by Razog            ###   ########.fr       */
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

	i = 0;
	while (i < game->draw_start)
		game->image.pixels[i++ * game->screen_w + game->x] = \
		rgb_to_int(game->map->ceiling_color);
	while (i < game->draw_end)
		game->image.pixels[i++ * game->screen_w + game->x] = \
		rgb_to_int(0xFF0000);
	while (i < game->screen_h)
		game->image.pixels[i++ * game->screen_w + game->x] = \
		rgb_to_int(game->map->floor_color);
}
