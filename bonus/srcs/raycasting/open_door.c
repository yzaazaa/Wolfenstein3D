/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:11:52 by Razog             #+#    #+#             */
/*   Updated: 2024/05/18 13:13:27 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	put_string_door(t_datas *game)
{
	if (game->map->map2d[(int)(game->pos_x + game->x_dir)][(int)(\
		game->pos_y + game->y_dir)] == 'D')
		mlx_string_put(game->mlx, game->mlx_win,
			game->screen_w / 2 - game->screen_w / 10,
			game->screen_h - game->screen_h / 4, 0xFFFFFF,
			"Press space to open door");
	if (game->map->map2d[(int)(game->pos_x + game->x_dir)][(int)(\
		game->pos_y + game->y_dir)] == 'd')
		mlx_string_put(game->mlx, game->mlx_win,
			game->screen_w / 2 - game->screen_w / 10,
			game->screen_h - game->screen_h / 4, 0xFFFFFF,
			"Press space to close door");
}

void	open_door(t_datas *game)
{
	game->open_door = 0;
	if (game->map->map2d[(int)(game->pos_x + game->x_dir)][(int)(\
		game->pos_y + game->y_dir)] == 'D')
		game->map->map2d[(int)(game->pos_x + game->x_dir)][(int)(\
		game->pos_y + game->y_dir)] = 'd';
	else if (game->map->map2d[(int)(game->pos_x + game->x_dir)][(int)(\
		game->pos_y + game->y_dir)] == 'd')
		game->map->map2d[(int)(game->pos_x + game->x_dir)][(int)(\
		game->pos_y + game->y_dir)] = 'D';
}
