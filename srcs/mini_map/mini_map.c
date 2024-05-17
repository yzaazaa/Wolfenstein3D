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

void	init_pixels(t_datas *game, t_point *offset, t_point *starting_pixel, t_point *end_pixel, t_point *player)
{
	offset->x = 0;
	offset->y = 0;
	player->x = floor(game->pos_x) - (MINI_MAP_SIZE / 2);
	if (player->x + MINI_MAP_SIZE > game->map->row)
		player->x = game->map->row - MINI_MAP_SIZE;
	if (player->x < 0)
		player->x = 0;
	player->y = floor(game->pos_y) - (MINI_MAP_SIZE / 2);
	if (player->y + MINI_MAP_SIZE >  game->map->col)
		player->y = game->map->col - MINI_MAP_SIZE;
	if (player->y < 0)
		player->y = 0;
	starting_pixel->x = offset->x;
	starting_pixel->y = offset->y;
	end_pixel->x = offset->x + (MINI_MAP_SIZE * TILE_SIZE);
	end_pixel->y = offset->y + (MINI_MAP_SIZE * TILE_SIZE);
}

void	reset_y_vars(t_datas *game, t_point offset, t_point *starting_pixel, t_point *player)
{
	starting_pixel->y = offset.y;
	player->y = floor(game->pos_y) - (MINI_MAP_SIZE / 2);
	if (player->y + MINI_MAP_SIZE >  game->map->col)
		player->y = game->map->col - MINI_MAP_SIZE;
	if (player->y < 0)
		player->y = 0;
}

void	choose_color(t_datas *game, t_point player, int *color)
{
	if (player.y == floor(game->pos_y) && player.x == floor(game->pos_x))
		*color = 0xFF0000;
	else if (game->map->map2d[player.x][player.y] == '1')
		*color = 0x000000;
	else if (game->map->map2d[player.x][player.y] == 'D' || game->map->map2d[player.x][player.y] == 'd')
		*color = 0x00FFFF;
	else
		*color = 0xFFFFFF;
}

void	draw_mini_map(t_datas *game)
{
	int	color;
	t_point	offset;
	t_point	starting_pixel;
	t_point	end_pixel;
	t_point	player;

	init_pixels(game, &offset, &starting_pixel, &end_pixel, &player);
	while (starting_pixel.x < end_pixel.x && game->map->map2d[player.x])
	{
		reset_y_vars(game, offset, &starting_pixel, &player);
		while (starting_pixel.y < end_pixel.y && game->map->map2d[player.x][player.y])
		{
			choose_color(game, player, &color);
			draw_square(game, starting_pixel, TILE_SIZE, color);
			starting_pixel.y += TILE_SIZE;
			player.y++;
		}
		starting_pixel.x += TILE_SIZE;
		player.x++;
	}
}
