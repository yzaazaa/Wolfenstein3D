#include "cub3d.h"

void	put_pixel(t_datas *game, int x, int y, int color)
{
	if (x < 0 || x >= game->screen_w || y < 0 || y >= game->screen_h)
		return ;
	game->image.pixels[y * game->screen_w + x] = color;
}

void	draw_circle(t_datas *game, int center_x, int center_y, int radius, int color)
{
	int x = 0;
	int y = radius;
	int d = 1 - radius;

	put_pixel(game, center_x + x, center_y + y, color);
	put_pixel(game, center_x - x, center_y + y, color);
	put_pixel(game, center_x + x, center_y - y, color);
	put_pixel(game, center_x - x, center_y - y, color);
	put_pixel(game, center_x + y, center_y + x, color);
	put_pixel(game, center_x - y, center_y + x, color);
	put_pixel(game, center_x + y, center_y - x, color);
	put_pixel(game, center_x - y, center_y - x, color);
	while (x < y)
	{
		x++;
		if (d < 0)
			d = d + 2 * x + 1;
		else
		{
			y--;
			d = d + 2 * (x - y) + 1;
		}
		put_pixel(game, center_x + x, center_y + y, color);
		put_pixel(game, center_x - x, center_y + y, color);
		put_pixel(game, center_x + x, center_y - y, color);
		put_pixel(game, center_x - x, center_y - y, color);
		put_pixel(game, center_x + y, center_y + x, color);
		put_pixel(game, center_x - y, center_y + x, color);
		put_pixel(game, center_x + y, center_y - x, color);
		put_pixel(game, center_x - y, center_y - x, color);
    }
}

void	draw_crosshair(t_datas *game)
{
	draw_circle(game, game->screen_w / 2, game->screen_h / 2, 10, 0xFF0000);
	put_pixel(game, game->screen_w / 2, game->screen_h / 2, 0xFF0000);
}