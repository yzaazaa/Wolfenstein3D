/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:11:52 by Razog             #+#    #+#             */
/*   Updated: 2024/05/17 16:53:51 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
