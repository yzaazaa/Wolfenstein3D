/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:10:49 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:10:51 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_gun(t_datas *game)
{
	if (game->sprite_index < 3)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->shoot1, game->screen_w / 2, game->screen_h - 500);
	else if (game->sprite_index < 6)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->shoot2, game->screen_w / 2, game->screen_h - 500);
	else if (game->sprite_index < 9)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->shoot3, game->screen_w / 2, game->screen_h - 500);
	else if (game->sprite_index < 12)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->shoot4, game->screen_w / 2, game->screen_h - 500);
}
