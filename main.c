/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:42:46 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/11 03:37:39 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// // void f(){system("leaks cub3d");}
// int	main(int ac, char **av)
// {
// 	// atexit(f);
// 	t_map	*map;
// 	t_datas	*data;

// 	if (ac != 2)
// 		puterr(INVALID_ARG);
// 	map = parse_map(av[1]);
// 	data = malloc(sizeof(t_datas));
// 	if (!data)
// 		puterr(MALLOC_ERR);
// 	data->map = map;
// 	data->pos_x = map->pos_x;
// 	data->pos_y = map->pos_y;
// 	launch_game(data);
// 	free_map(map);
// 	free(data);
// 	return (0);
// }

static void	load_texture(t_datas *game, char *path_to_texture, int **data)
{
	void	*image;
	int		nb;

	nb = 0;
	image = mlx_xpm_file_to_image(game->mlx, path_to_texture, &nb, &nb);
	if (!image)
		puterr(CONVERT_XPM_ERR);
	*data = (int *)mlx_get_data_addr(image, &nb, &nb, &nb);
	if (!*data)
		puterr(MLX_IMAGE_DATA_ERR);
}

static void	load_textures(t_datas *game)
{
	load_texture(game, game->map->north_texture, &game->textures.north);
	load_texture(game, game->map->south_texture, &game->textures.south);
	load_texture(game, game->map->east_texture, &game->textures.east);
	load_texture(game, game->map->west_texture, &game->textures.west);
}

int	main(int ac, char **av)
{
	t_datas game;
	t_map	*map;

	if (ac != 2)
		puterr(INVALID_ARG);
	init_game(&game);
	map = parse_map(av[1]);
	game.map = map;
	// print_map_content(map);
	load_textures(&game);
	start_game(&game);
	mlx_hook(game.mlx_win, 2, 0, &key_pressed, &game);
	mlx_hook(game.mlx_win, 3, 0, &key_released, &game);
	mlx_hook(game.mlx_win, 6, 0, &ft_mouse, &game);
	mlx_loop_hook(game.mlx, launch_game, &game);
	mlx_loop(game.mlx);
	free_map(map);
	return (0);
}
