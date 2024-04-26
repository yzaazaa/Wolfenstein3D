/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:07:48 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/26 17:12:15 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(t_datas *data, char *msg)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	printf("%s", msg);
	free_map(data->map);
	free(data);
	exit(EXIT_SUCCESS);
}

int	ft_close_win(t_datas *data)
{
	ft_free(data, "WINDOW CLOSED\n");
	return (0);
}

void	init_game(t_datas *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		puterr(MLX_ERR);
	game->screen_h = 1024;
	game->screen_w = 1024;
	game->x = 0;
	game->pos_x = 0;
	game->pos_y = 0;
	game->mlx_win = mlx_new_window(game->mlx,
			game->screen_w, game->screen_h, "cub3D");
	if (!game->mlx_win)
		puterr(MLX_WINDOW_ERR);
	game->image.ptr = mlx_new_image(game->mlx, game->screen_w, game->screen_h);
	if (!game->image.ptr)
	{
		mlx_destroy_image(game->mlx, game->mlx_win);
		puterr(MLX_IMAGE_ERR);
	}
	game->image.pixels = mlx_get_data_addr(game->image.ptr,
			&game->image.bpp, &game->image.line_len, &game->image.endian);
	if (!game->image.pixels)
	{
		ft_close_win(game);
		puterr(MLX_IMAGE_DATA_ERR);
	}
}

int	launch_game(t_datas *data)
{
	init_game(data);
	//draw(&data);
	mlx_hook(data->mlx_win, WIN_CLOSE, 0, ft_close_win, data);
	mlx_hook(data->mlx_win, 2, 0, &key_pressed, data);
	mlx_hook(data->mlx_win, 3, 0, &key_released, data);
	mlx_loop(data->mlx);
	return (0);
}
