/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:42:46 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 13:14:13 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_texture(t_datas *game, char *path, t_image *img)
{
	int		width;
	int		height;

	img->ptr = mlx_xpm_file_to_image(game->mlx, path, &height, &width);
	if (!img->ptr || width != 64 || height != 64)
		puterr(CONVERT_XPM_ERR, game, NULL);
	img->pixels = (int *)mlx_get_data_addr(img->ptr,
			&img->bpp, &img->line_len, &img->endian);
	if (!img->pixels)
		puterr(MLX_IMAGE_DATA_ERR, game, NULL);
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