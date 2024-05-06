/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:01:27 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/06 20:03:37 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//calculate step and initial sideDist
void	calc_side_dist_step(t_datas *data)
{
	if (data->x_raydir < 0)
	{
		data->x_step = -1;
		data->side_x_dist = (data->pos_x - data->map_x) * data->delta_x_dist;
	}
	else
	{
		data->x_step = 1;
		data->side_x_dist = (data->map_x + 1.0 - data->pos_x) * data->delta_x_dist;
	}
	if (data->y_raydir < 0)
	{
		data->y_step = -1;
		data->side_y_dist = (data->pos_y - data->map_y) * data->delta_y_dist;
	}
	else
	{
		data->y_step = 1;
		data->side_y_dist = (data->map_y + 1.0 - data->pos_y) * data->delta_y_dist;
	}
}

void	init_ray_distance(t_datas *data)
{
	//which box of the map we're in
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	//calculate ray position and direction
	data->camera_x = 2 * (data->x / (double)(data->screen_w)) - 1;
	data->x_raydir = data->x_dir + data->x_plane \
		* data->camera_x;
	data->y_raydir = data->y_dir + data->y_plane \
		* data->camera_x;
	//length of ray from one x or y-side to next x or y-side
	data->delta_x_dist = sqrt(1 + pow(data->y_raydir, 2) \
		/ pow(data->x_raydir, 2));
	data->delta_y_dist = sqrt(1 + pow(data->x_raydir, 2) \
		/ pow(data->y_raydir, 2));
	data->hit_wall = 0;
	calc_side_dist_step(data);
}

void	raycasting(t_datas *data)
{
	//perform DDA
	while (data->hit_wall == 0)
	{
		if (data->side_x_dist < data->side_y_dist)
		{
			data->side_x_dist += data->delta_x_dist;
			data->map_x += data->x_step;
			data->side = 0;
		}
		else
		{
			data->side_y_dist += data->delta_y_dist;
			data->map_y += data->y_step;
			data->side = 1;
		}
		if (data->map->map2d[data->map_y][data->map_x] == '1')
			data->hit_wall = 1;
	}
	//Calculate distance projected on camera direction (Euclidean)
	if (data->side == 0)
		data->perp_dist_wall = fabs((data->map_x - data->pos_x + \
		(1 - data->x_step) / 2) / data->x_raydir);
	else
		data->perp_dist_wall = fabs((data->map_y - data->pos_y + \
		(1 - data->y_step) / 2) / data->y_raydir);
}

void	calc_wall_height(t_datas *data)
{
	//Calculate height of line to draw on screen
	if (!data->perp_dist_wall)
		data-> perp_dist_wall= 1;
	data->line_height = (int)(data->screen_h \
		/ data->perp_dist_wall);
	//calculate lowest and highest pixel to fill in current stripe
	data->draw_start = -data->line_height / 2 + data->screen_h / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + data->screen_h / 2;
	if (data->draw_end >= data->screen_h)
		data->draw_end = data->screen_h - 1;
}

int	launch_game(void *ptr)
{
	t_datas *game;

	game = ptr;
	mlx_clear_window(game->mlx, game->mlx_win);
	drawing(game);
	return(0);
}