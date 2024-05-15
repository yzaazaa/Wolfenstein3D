#include "cub3d.h"

void	draw_square(t_datas *game, t_point begin, int size, int color)
{
	int	i;
	int	j;

	i = begin.x;
	while (i < begin.x + size)
	{
		j = begin.y;
		while (j < begin.y + size)
		{
			game->image.pixels[i * game->screen_w + j] = color;
			j++;
		}
		i++;
	}
}

void	draw_mini_map(t_datas *game)
{
	int	color;
	int	i;
	int	j;
	int	offset_x;

	offset_x = game->screen_w / 2 - (ft_strlen(game->map->map2d[0]) * TILE_SIZE) / 2;
	i = 0;
	while (i < game->map->row)
	{
		j = 0;
		while (game->map->map2d[i][j] != '\0')
		{
			if (game->map->map2d[i][j] == '1')
				color = 0;
			else if (game->map->map2d[i][j] == 'D')
				color = 0x632b02;
			else
				color = 0xFFFFFF;
				draw_square(game, (t_point){i * TILE_SIZE, offset_x + j * TILE_SIZE}, TILE_SIZE, color);
				j++;
		}
		i++;
	}
	draw_square(game, (t_point){floor(game->pos_x) * TILE_SIZE, offset_x + floor(game->pos_y) * TILE_SIZE}, TILE_SIZE, 0xFF0000);
}