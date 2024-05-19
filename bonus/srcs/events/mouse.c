/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:10:35 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/19 16:40:39 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_mouse(int x, int y, t_datas *vars)
{
	static int	prev_x = -1;
	int	diff;

	(void)y;
	if (x != prev_x && prev_x != -1)
	{
		diff = abs(prev_x - x);
		if (x > prev_x)
			while (diff--)
				rotate(vars, -vars->rote_angle * MOUSE_SENSITIVITY / 10);
		else
			while (diff--)
				rotate(vars, vars->rote_angle * MOUSE_SENSITIVITY / 10);
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
