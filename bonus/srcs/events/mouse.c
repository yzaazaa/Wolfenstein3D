/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:10:35 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:10:37 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_mouse(int x, int y, t_datas *vars)
{
	static int	prev_x = -1;
	int			diff;

	(void)y;
	if (x != prev_x)
	{
		diff = (prev_x != -1) * ((x - prev_x) > 0);
		diff = (diff * 2) - 1;
		rotate(vars, (-diff * vars->rote_angle) * MOUSE_SENSITIVITY);
	}
	prev_x = x;
	return (0);
}

int	shoot(int button, int x, int y, void *param)
{
	t_datas	*game;

	(void)x;
	(void)y;
	game = param;
	if (button == 1)
		game->sprite_index = 2;
	return (0);
}
