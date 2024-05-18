/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:14:27 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:14:28 by yzaazaa          ###   ########.fr       */
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

void	load_textures(t_datas *game)
{
	load_texture(game, game->map->north_texture, &game->textures.north);
	load_texture(game, game->map->south_texture, &game->textures.south);
	load_texture(game, game->map->east_texture, &game->textures.east);
	load_texture(game, game->map->west_texture, &game->textures.west);
}
