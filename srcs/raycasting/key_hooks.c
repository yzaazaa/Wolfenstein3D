/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:54:55 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/09 15:11:05 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	moves(t_datas *game)
{
	if (game->rot_right == 1)
		rotate(game, -(game->rote_angle));
	else if (game->rot_left == 1)
		rotate(game, game->rote_angle);
	else if (game->move_up == 1)
		move_forword(game);
	else if (game->move_down == 1)
		move_backword(game);
	else if (game->move_right == 1)
		move_right(game);
	else if (game->move_left == 1)
		move_left(game);
	game->x = 0;
}

int	key_pressed(int key, t_datas *game_ptr)
{
	if (key == RIGHT_R)
		game_ptr->rot_right = 1;
	else if (key == LEFT_R)
		game_ptr->rot_left = 1;
	else if (key == UP_M)
		game_ptr->move_up = 1;
	else if (key == DOWN_M)
		game_ptr->move_down = 1;
	else if (key == RIGHT_M)
		game_ptr->move_right = 1;
	else if (key == LEFT_M)
		game_ptr->move_left = 1;
	else if (key == ESC_KEY)
		ft_close_win(game_ptr);
	else
		return (1);
	return (0);
}

int	key_released(int key, t_datas *game_ptr)
{
	if (key == RIGHT_R)
		game_ptr->rot_right = 0;
	else if (key == LEFT_R)
		game_ptr->rot_left = 0;
	else if (key == UP_M)
		game_ptr->move_up = 0;
	else if (key == DOWN_M)
		game_ptr->move_down = 0;
	else if (key == RIGHT_M)
		game_ptr->move_right = 0;
	else if (key == LEFT_M)
		game_ptr->move_left = 0;
	else
		return (1);
	return (0);
}
