/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:11:19 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:11:21 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_square(t_datas *game, t_point begin, int size, int color)
{
	int	i;
	int	j;

	i = begin.x;
	while (i < begin.x + size)
	{
		j = begin.y;
		while (j < begin.y + size)
		{
			put_pixel(game, i, j, color);
			j++;
		}
		i++;
	}
}

static void	init(t_datas *game, t_point *off, t_point *end_pixel, t_point *p)
{
	off->x = 0;
	off->y = 0;
	p->x = floor(game->pos_x) - (MINI_MAP_SIZE / 2);
	if (p->x + MINI_MAP_SIZE > game->map->row)
		p->x = game->map->row - MINI_MAP_SIZE;
	if (p->x < 0)
		p->x = 0;
	p->y = floor(game->pos_y) - (MINI_MAP_SIZE / 2);
	if (p->y + MINI_MAP_SIZE > game->map->col)
		p->y = game->map->col - MINI_MAP_SIZE;
	if (p->y < 0)
		p->y = 0;
	end_pixel->x = off->x + (MINI_MAP_SIZE * TILE_SIZE);
	end_pixel->y = off->y + (MINI_MAP_SIZE * TILE_SIZE);
}

static void	reset_y(t_datas *game, t_point off, t_point *start, t_point *p)
{
	start->y = off.y;
	p->y = floor(game->pos_y) - (MINI_MAP_SIZE / 2);
	if (p->y + MINI_MAP_SIZE > game->map->col)
		p->y = game->map->col - MINI_MAP_SIZE;
	if (p->y < 0)
		p->y = 0;
}

static void	choose_color(t_datas *game, t_point player, int *color)
{
	if (player.y == floor(game->pos_y) && player.x == floor(game->pos_x))
		*color = 0xFF0000;
	else if (game->map->map2d[player.x][player.y] == '1')
		*color = 0x000000;
	else if (game->map->map2d[player.x][player.y] == 'D'
		|| game->map->map2d[player.x][player.y] == 'd')
		*color = 0x00FFFF;
	else
		*color = 0xFFFFFF;
}

void	draw_mini_map(t_datas *game)
{
	int		color;
	t_point	offset;
	t_point	starting_pixel;
	t_point	end_pixel;
	t_point	player;

	init(game, &offset, &end_pixel, &player);
	starting_pixel.x = offset.x;
	starting_pixel.y = offset.y;
	while (starting_pixel.x < end_pixel.x && game->map->map2d[player.x])
	{
		reset_y(game, offset, &starting_pixel, &player);
		while (starting_pixel.y < end_pixel.y
			&& game->map->map2d[player.x][player.y])
		{
			choose_color(game, player, &color);
			draw_square(game, starting_pixel, TILE_SIZE, color);
			starting_pixel.y += TILE_SIZE;
			player.y++;
		}
		starting_pixel.x += TILE_SIZE;
		player.x++;
	}
}
