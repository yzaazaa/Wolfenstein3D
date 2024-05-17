/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:57:00 by Razog             #+#    #+#             */
/*   Updated: 2024/05/17 16:53:22 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	put_pixel(t_datas *game, int x, int y, int color)
{
	if (x < 0 || x >= game->screen_w || y < 0 || y >= game->screen_h)
		return ;
	game->image.pixels[y * game->screen_w + x] = color;
}

static void	circle_help(t_datas *game, t_point center, t_point pixel, int color)
{
	put_pixel(game, center.x + pixel.x, center.y + pixel.y, color);
	put_pixel(game, center.x - pixel.x, center.y + pixel.y, color);
	put_pixel(game, center.x + pixel.x, center.y - pixel.y, color);
	put_pixel(game, center.x - pixel.x, center.y - pixel.y, color);
	put_pixel(game, center.x + pixel.y, center.y + pixel.x, color);
	put_pixel(game, center.x - pixel.y, center.y + pixel.x, color);
	put_pixel(game, center.x + pixel.y, center.y - pixel.x, color);
	put_pixel(game, center.x - pixel.y, center.y - pixel.x, color);
}

static void	init(int *x, int *y, int *d, int radius)
{
	*x = 0;
	*y = radius;
	*d = 1 - radius;
}

static void	draw_circle(t_datas *game, t_point center, int radius, int color)
{
	int	x;
	int	y;
	int	d;

	init(&x, &y, &d, radius);
	circle_help(game, center, (t_point){x, y}, color);
	while (x < y)
	{
		x++;
		if (d < 0)
			d = d + 2 * x + 1;
		else
		{
			y--;
			d = d + 2 * (x - y) + 1;
		}
		put_pixel(game, center.x + x, center.y + y, color);
		put_pixel(game, center.x - x, center.y + y, color);
		put_pixel(game, center.x + x, center.y - y, color);
		put_pixel(game, center.x - x, center.y - y, color);
		put_pixel(game, center.x + y, center.y + x, color);
		put_pixel(game, center.x - y, center.y + x, color);
		put_pixel(game, center.x + y, center.y - x, color);
		put_pixel(game, center.x - y, center.y - x, color);
	}
}

void	draw_crosshair(t_datas *game)
{
	t_point	center;

	center = (t_point){game->screen_w / 2, game->screen_h / 2};
	draw_circle(game, center, 10, 0xFF0000);
	put_pixel(game, game->screen_w / 2, game->screen_h / 2, 0xFF0000);
}
