/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:54:55 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/27 21:03:52 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	update_game(t_datas *game)
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

int	key_pressed(int key, t_datas *data)
{
	if (key == ESC_KEY)
		ft_close_win(data);
	else if (key == KEY_W)
		data->w_key_pressed = 1;
	else if (key == KEY_S)
		data->s_key_pressed = 1;
	else if (key == KEY_A)
		data->a_key_pressed = 1;
	else if (key == KEY_D)
		data->d_key_pressed = 1;
	else if (key == KEY_LEFT)
		data->left_key_pressed = 1;
	else if (key == KEY_RIGHT)
		data->right_key_presed = 1;
	else
		return (1);
	return (0);
}

int	key_released(int key, t_datas *data)
{
	if (key == KEY_W)
		data->w_key_pressed = 0;
	else if (key == KEY_S)
		data->s_key_pressed = 0;
	else if (key == KEY_A)
		data->a_key_pressed = 0;
	else if (key == KEY_D)
		data->d_key_pressed = 0;
	else if (key == KEY_LEFT)
		data->left_key_pressed = 0;
	else if (key == KEY_RIGHT)
		data->right_key_presed = 0;
	return (0);
}
