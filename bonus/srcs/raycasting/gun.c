/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:04:48 by Razog             #+#    #+#             */
/*   Updated: 2024/05/18 13:11:46 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	shoot(int button, int x, int y, void *param)
{
	t_datas	*game;

	(void)x;
	(void)y;
	game = param;
	if (button == 1)
		game->sprite_index = 10;
	return (0);
}

void	draw_gun(t_datas *game)
{
	if (game->sprite_index < 3)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->shoot1, game->screen_w / 2, game->screen_h - 500);
	else if (game->sprite_index < 13)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->shoot2, game->screen_w / 2, game->screen_h - 500);
	else if (game->sprite_index < 16)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->shoot3, game->screen_w / 2, game->screen_h - 500);
	else if (game->sprite_index < 19)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->shoot4, game->screen_w / 2, game->screen_h - 500);
}
