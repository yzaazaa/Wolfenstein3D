/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:07:48 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/17 16:59:04 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(t_datas *data, char *msg)
{
	mlx_destroy_image(data->mlx, data->image.ptr);
	if (data->map)
		free_map(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	if (msg)
		printf("%s", msg);
	exit(EXIT_SUCCESS);
}

int	ft_close_win(t_datas *data)
{
	ft_free(data, "WINDOW CLOSED\n");
	return (0);
}

void	ft_new_window(t_datas *game)
{
	game->mlx_win = mlx_new_window(game->mlx,
			game->screen_w, game->screen_h, "cub3D");
	if (!game->mlx_win)
		puterr(MLX_WINDOW_ERR, game, NULL);
	mlx_hook(game->mlx_win, WIN_CLOSE, 0, ft_close_win, game);
}
