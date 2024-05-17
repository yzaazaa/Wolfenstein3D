/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:42:46 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/17 21:46:45 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	load_texture(t_datas *game, char *path_to_texture, int **data, t_point size)
{
	void	*image;
	int		width;
	int		height;

	image = mlx_xpm_file_to_image(game->mlx, path_to_texture, &width, &height);
	if (!image || width != size.x || height != size.y)
		puterr(CONVERT_XPM_ERR, game, NULL);
	*data = (int *)mlx_get_data_addr(image, &height, &height, &height);
	if (!*data)
		puterr(MLX_IMAGE_DATA_ERR, game, NULL);
}

static void	load_textures(t_datas *game)
{
	int		width;
	int		height;

	load_texture(game, game->map->north_texture, &game->textures.north, (t_point){TEX_SIZE, TEX_SIZE});
	load_texture(game, game->map->south_texture, &game->textures.south, (t_point){TEX_SIZE, TEX_SIZE});
	load_texture(game, game->map->east_texture, &game->textures.east, (t_point){TEX_SIZE, TEX_SIZE});
	load_texture(game, game->map->west_texture, &game->textures.west, (t_point){TEX_SIZE, TEX_SIZE});
	load_texture(game, "textures/wolfenstein/door.xpm", &game->textures.door, (t_point){TEX_SIZE, TEX_SIZE});
	game->shoot1 = mlx_xpm_file_to_image(game->mlx, "sprites/shoot1.xpm", &width, &height);
	if (!game->shoot1 || width != 500 || height != 500)
		puterr(CONVERT_XPM_ERR, game, NULL);
	// game->shoot2 = mlx_xpm_file_to_image(game->mlx, "sprites/shoot2.xpm", &width, &height);
	// if (!game->shoot2 || width != 500 || height != 500)
	// 	puterr(CONVERT_XPM_ERR, game, NULL);
	// game->shoot3 = mlx_xpm_file_to_image(game->mlx, "sprites/shoot3.xpm", &width, &height);
	// if (!game->shoot3 || width != 500 || height != 500)
	// 	puterr(CONVERT_XPM_ERR, game, NULL);
	// game->shoot4 = mlx_xpm_file_to_image(game->mlx, "sprites/shoot4.xpm", &width, &height);
	// if (!game->shoot4 || width != 500 || height != 500)
	// 	puterr(CONVERT_XPM_ERR, game, NULL);
}

void f()
{
	system("leaks cub3d_bonus");
}

int	main(int ac, char **av)
{
	t_datas	game;
	t_map	map;

	// atexit(f);
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
	mlx_hook(game.mlx_win, 6, 0, &ft_mouse, &game);
	mlx_hook(game.mlx_win, 4, 0, &shoot, &game);
	mlx_loop_hook(game.mlx, launch_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
