/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:07:48 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/06 13:59:01 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	ft_free(t_datas *data, char *msg)
{
	mlx_destroy_image(data->mlx, data->image.ptr);
	mlx_destroy_window(data->mlx, data->mlx_win);
	printf("%s", msg);
	free_map(data->map);
	// free(data);
	exit(EXIT_SUCCESS);
}

int	ft_close_win(t_datas *data)
{
	ft_free(data, "WINDOW CLOSED\n");
	return (0);
}

void	ft_new_window(t_datas *game)
{
	game->mlx_win = mlx_new_window(game->mlx, game->screen_w, game->screen_h, "cub3D");
	mlx_hook(game->mlx_win, WIN_CLOSE, 0, ft_close_win, game);
}

// static void	puterr_close_win(t_datas *data, char *s)
// {
// 	if (s)
// 		write(2, s, ft_strlen(s));
// 	ft_close_win(data);
// }

// static void	init_rot_angle(t_datas *data)
// {
// 	char	angle;

// 	angle = data->map->spawn_orientation;
// 	if (angle == 'N')
// 		data->rote_angle = M_PI_2;
// 	else if (angle == 'E')
// 		data->rote_angle = 0;
// 	else if (angle == 'W')
// 		data->rote_angle = M_PI;
// 	else if (angle == 'S')
// 		data->rote_angle = (M_PI / 4) + (2 * M_PI / 4);
// }

// static void	generate_texture(t_datas *game, char *path_to_texture, char **orientation)
// {
// 	void	*image;

// 	image = mlx_xpm_file_to_image(game->mlx, path_to_texture, 0, 0);
// 	if (!image)
// 		puterr_close_win(game, CONVERT_XPM_ERR);
// 	*orientation = mlx_get_data_addr(image, 0, 0, 0);
// 	if (!*orientation)
// 		puterr_close_win(game, MLX_IMAGE_DATA_ERR);
// }

// static void	get_textures(t_datas *game)
// {
// 	generate_texture(game, game->map->north_texture, &game->textures.north);
// 	generate_texture(game, game->map->south_texture, &game->textures.south);
// 	generate_texture(game, game->map->east_texture, &game->textures.east);
// 	generate_texture(game, game->map->west_texture, &game->textures.west);
// }

// void	init_game(t_datas *game)
// {
// 	game->mlx = mlx_init();
// 	if (!game->mlx)
// 		puterr(MLX_ERR);
// 	game->screen_h = 1024;
// 	game->screen_w = 1024;
// 	game->x = 0;
// 	game->pos_x = game->map->pos_x * TILE_SIZE + TILE_SIZE / 2;
// 	game->pos_y = game->map->pos_y * TILE_SIZE + TILE_SIZE / 2;
// 	init_rot_angle(game);
// 	game->fov_rd = FOV * M_PI / 180;
// 	game->mlx_win = mlx_new_window(game->mlx,
// 			game->screen_w, game->screen_h, "cub3D");
// 	if (!game->mlx_win)
// 		puterr(MLX_WINDOW_ERR);
// 	// get_textures(game);
// 	game->image.ptr = mlx_new_image(game->mlx, game->screen_w, game->screen_h);
// 	if (!game->image.ptr)
// 	{
// 		mlx_destroy_image(game->mlx, game->mlx_win);
// 		puterr(MLX_IMAGE_ERR);
// 	}
// 	game->image.pixels = (int *)mlx_get_data_addr(game->image.ptr,
// 			&game->image.bpp, &game->image.line_len, &game->image.endian);
// 	if (!game->image.pixels)
// 		puterr_close_win(game, MLX_IMAGE_DATA_ERR);
// }

// int	render(t_datas *game)
// {
// 	mlx_clear_window(game->mlx, game->mlx_win);
// 	update_game(game);
// 	while (game->x < game->screen_w)
// 	{
// 		init_ray_distance(game);
// 		raycasting(game);
// 		calc_wall_height(game);
// 		//draw_wall(game);
// 		draw_floor_ceiling(game);
// 		game->x++;
// 	}
// 	mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.ptr, 0, 0);
// 	return (0);
// }
