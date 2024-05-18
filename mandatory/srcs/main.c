/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:42:46 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:21:03 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(t_datas *data, char *msg)
{
	if (data->image.ptr)
		mlx_destroy_image(data->mlx, data->image.ptr);
	if (data->textures.north.ptr)
		mlx_destroy_image(data->mlx, data->textures.north.ptr);
	if (data->textures.south.ptr)
		mlx_destroy_image(data->mlx, data->textures.south.ptr);
	if (data->textures.east.ptr)
		mlx_destroy_image(data->mlx, data->textures.east.ptr);
	if (data->textures.west.ptr)
		mlx_destroy_image(data->mlx, data->textures.west.ptr);
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

static int	launch_game(void *ptr)
{
	t_datas	*game;

	game = ptr;
	mlx_destroy_image(game->mlx, game->image.ptr);
	game->image.ptr = mlx_new_image(game->mlx, game->screen_w, game->screen_h);
	if (!game->image.ptr)
		puterr(MLX_IMAGE_ERR, game, NULL);
	game->image.pixels = (int *)mlx_get_data_addr(game->image.ptr,
			&(game->image.bpp),
			&(game->image.line_len), &(game->image.endian));
	if (!game->image.pixels)
		puterr(MLX_IMAGE_DATA_ERR, game, NULL);
	moves(game);
	drawing(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.ptr, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_datas	game;
	t_map	map;

	ft_memset(&game, 0, sizeof(t_datas));
	ft_memset(&map, 0, sizeof(t_map));
	if (ac != 2)
		puterr(INVALID_ARG, NULL, NULL);
	init_game(&game);
	parse_map(&map, av[1]);
	game.map = &map;
	load_textures(&game);
	start_game(&game);
	mlx_hook(game.mlx_win, 2, 0, &key_pressed, &game);
	mlx_hook(game.mlx_win, 3, 0, &key_released, &game);
	mlx_loop_hook(game.mlx, launch_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
