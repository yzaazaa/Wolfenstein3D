/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:42:46 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/16 17:05:41 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	load_texture(game, "textures/wolfenstein/door.xpm", &game->textures.door);
}

int	main(int ac, char **av)
{
	t_datas game;
	t_map	*map;

	ft_memset(&game, 0, sizeof(t_datas));
	if (ac != 2)
		puterr(INVALID_ARG);
	init_game(&game);
	map = parse_map(av[1]);
	game.map = map;
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
