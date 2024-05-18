/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:57:00 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 18:25:16 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_datas *game, int x, int y, int color)
{
	if (x < 0 || x >= game->screen_w || y < 0 || y >= game->screen_h)
		return ;
	game->image.pixels[y * game->screen_w + x] = color;
}
