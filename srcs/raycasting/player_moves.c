/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:09:07 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/06 19:55:52 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forword(t_datas *game)
{
	if (game->map->map2d[(int)(game->pos_x + game->x_dir)][(int)(\
		game->pos_y + game->y_dir)] == '0' || game->map->map2d[(int)(game->pos_x + game->x_dir)][(int)(game->pos_y + game->y_dir)] == ' ')
	{
		game->pos_x += game->x_dir * game->movespeed;
		game->pos_y += game->y_dir * game->movespeed;
	}
}

void	move_backword(t_datas *game)
{
	if (game->map->map2d[(int)(game->pos_x - game->x_dir)][(int)(\
		game->pos_y - game->y_dir)] == '0' || game->map->map2d[(int)(game->pos_x - game->x_dir)][(int)(\
		game->pos_y - game->y_dir)] == ' ')
	{
		game->pos_x -= game->x_dir * game->movespeed;
		game->pos_y -= game->y_dir * game->movespeed;
	}
}

void	move_left(t_datas *game)
{
	if (game->map->map2d[(int)(game->pos_x)][(int)(\
		game->pos_y + game->y_dir - game->y_plane)] == '0' || game->map->map2d[(int)(game->pos_x)][(int)(\
		game->pos_y + game->y_dir - game->y_plane)] == ' ')
	{
		game->pos_y -= game->y_plane * game->movespeed;
		game->pos_x -= game->x_plane * game->movespeed;
	}
}

void	move_right(t_datas *game)
{
	if (game->map->map2d[(int)(game->pos_x)][(int)(\
		game->pos_y + game->y_dir + game->y_plane)] == '0' || game->map->map2d[(int)(game->pos_x)][(int)(\
		game->pos_y + game->y_dir + game->y_plane)] == ' ')
	{
		game->pos_y += game->y_plane * game->movespeed;
		game->pos_x += game->x_plane * game->movespeed;
	}
}

void	rotate(t_datas *game, double angle)
{
	double	old_dirx;
	double	old_planex;

	old_planex = game->x_plane;
	old_dirx = game->x_dir;
	game->x_dir = game->x_dir * cos(angle) - \
		game->y_dir * sin(angle);
	game->y_dir = old_dirx * sin(angle) + game->y_dir * cos(angle);
	game->x_plane = game->x_plane * cos(angle) - \
		game->y_plane * sin(angle);
	game->y_plane = old_planex * sin(angle) + game->y_plane * cos (angle);
}
