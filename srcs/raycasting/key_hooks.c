/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:54:55 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/29 16:14:15 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	moves(t_datas *game)
{
	mlx_destroy_image(game->mlx, game->image.ptr);
	game->image.ptr = mlx_new_image(game->mlx, game->screen_w, game->screen_h);
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
	mlx_clear_window(game->mlx, game->mlx_win);
	game->x = 0;
	launch_game(game);
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
	moves(game_ptr);
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
	return (0);
}
