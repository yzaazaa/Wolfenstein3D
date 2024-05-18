/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:42:46 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 13:10:23 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	load_texture(t_datas *game, char *path, t_image *img, int size)
{
	int		width;
	int		height;

	img->ptr = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img->ptr || width != size || height != size)
		puterr(CONVERT_XPM_ERR, game, NULL);
	img->pixels = (int *)mlx_get_data_addr(img->ptr,
			&img->bpp, &img->line_len, &img->endian);
	if (!img->pixels)
		puterr(MLX_IMAGE_DATA_ERR, game, NULL);
}

static void	load_textures(t_datas *game)
{
	int			w;
	int			h;
	static int	t = TEX_SIZE;

	load_texture(game, game->map->north_texture, &game->textures.north, t);
	load_texture(game, game->map->south_texture, &game->textures.south, t);
	load_texture(game, game->map->east_texture, &game->textures.east, t);
	load_texture(game, game->map->west_texture, &game->textures.west, t);
	load_texture(game, game->map->door_texture, &game->textures.door, t);
	game->shoot1 = mlx_xpm_file_to_image(game->mlx, SPRITE1, &w, &h);
	if (!game->shoot1 || w != 500 || h != 500)
		puterr(CONVERT_XPM_ERR, game, NULL);
	game->shoot2 = mlx_xpm_file_to_image(game->mlx, SPRITE2, &w, &h);
	if (!game->shoot2 || w != 500 || h != 500)
		puterr(CONVERT_XPM_ERR, game, NULL);
	game->shoot3 = mlx_xpm_file_to_image(game->mlx, SPRITE3, &w, &h);
	if (!game->shoot3 || w != 500 || h != 500)
		puterr(CONVERT_XPM_ERR, game, NULL);
	game->shoot4 = mlx_xpm_file_to_image(game->mlx, SPRITE4, &w, &h);
	if (!game->shoot4 || w != 500 || h != 500)
		puterr(CONVERT_XPM_ERR, game, NULL);
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
	mlx_hook(game.mlx_win, 6, 0, &ft_mouse, &game);
	mlx_hook(game.mlx_win, 4, 0, &shoot, &game);
	mlx_loop_hook(game.mlx, launch_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
