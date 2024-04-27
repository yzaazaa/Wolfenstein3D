/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:24:38 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/27 19:40:57 by frukundo         ###   ########.fr       */
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
		game->image.arr[i * game->screen_w + game->x] = \
		rgb_to_int(game->map->ceiling_color);
	i = game->draw_end;
	while (++i < game->screen_h)
		game->image.arr[i * game->screen_w + game->x] = \
		rgb_to_int(game->map->floor_color);
}
