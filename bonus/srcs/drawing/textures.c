/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:10:22 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/20 14:17:46 by yzaazaa          ###   ########.fr       */
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

static void	load_sprite(t_datas *game, char *path, void **img_ptr, int size)
{
	int	w;
	int	h;

	*img_ptr = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img_ptr || w != size || h != size)
		puterr(CONVERT_XPM_ERR, game, NULL);
}

void	load_textures(t_datas *game)
{
	static int	t = TEX_SIZE;

	load_texture(game, game->map->north_texture, &game->textures.north, t);
	load_texture(game, game->map->south_texture, &game->textures.south, t);
	load_texture(game, game->map->east_texture, &game->textures.east, t);
	load_texture(game, game->map->west_texture, &game->textures.west, t);
	if (game->map->door_texture)
		load_texture(game, game->map->door_texture, &game->textures.door, t);
	load_sprite(game, SPRITE1, &game->shoot1, 500);
	load_sprite(game, SPRITE2, &game->shoot2, 500);
	load_sprite(game, SPRITE3, &game->shoot3, 500);
	load_sprite(game, SPRITE4, &game->shoot4, 500);
}
