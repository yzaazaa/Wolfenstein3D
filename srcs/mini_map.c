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
			game->image.pixels[j * game->screen_w + i] = color;
			j++;
		}
		i++;
	}
}

void	draw_mini_map(t_datas *game)
{
	int	color;
	int	offset_x;
	t_point	starting_pixel;
	t_point	end_pixel;
	t_point	player;

	offset_x = game->screen_w / 2 - ((MINI_MAP_SIZE / 2) * TILE_SIZE);
	player.x = floor(game->pos_x) - (MINI_MAP_SIZE / 2);
	if (player.x + MINI_MAP_SIZE > game->map->row)
		player.x = game->map->row - MINI_MAP_SIZE;
	if (player.x < 0)
		player.x = 0;
	player.y = floor(game->pos_y) - (MINI_MAP_SIZE / 2);
	if (player.y + MINI_MAP_SIZE >  game->map->col)
		player.y = game->map->col - MINI_MAP_SIZE;
	if (player.y < 0)
		player.y = 0;
	print_array(game->map->map2d);
	printf("initial position: %d, %d\n", (int)floor(game->pos_x), (int)floor(game->pos_y));
	printf("changed position: %d, %d\n", player.x, player.y);
	starting_pixel.x = offset_x;
	starting_pixel.y = 0;
	end_pixel.x = offset_x + (MINI_MAP_SIZE * TILE_SIZE);
	end_pixel.y = MINI_MAP_SIZE * TILE_SIZE;
	while (starting_pixel.x < end_pixel.x && game->map->map2d[player.x])
	{
		starting_pixel.y = 0;
		player.y = floor(game->pos_y) - (MINI_MAP_SIZE / 2);
		if (player.y + MINI_MAP_SIZE >  game->map->col)
			player.y = game->map->col - MINI_MAP_SIZE;
		if (player.y < 0)
			player.y = 0;
		while (starting_pixel.y < end_pixel.y && game->map->map2d[player.x][player.y])
		{
			if (player.y == floor(game->pos_y) && player.x == floor(game->pos_x))
				color = 0xFF0000;
			else if ((printf("%d, %d\n", player.x, player.y)), game->map->map2d[player.x][player.y] == '1')
				color = 0x000000;
			else
				color = 0xFFFFFF;
			draw_square(game, starting_pixel, TILE_SIZE, color);
			starting_pixel.y += TILE_SIZE;
			player.y++;
		}
		starting_pixel.x += TILE_SIZE;
		player.x++;
	}
}