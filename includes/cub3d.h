/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:14:08 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/15 21:40:53 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#	define CUB3D_H

#	include <mlx.h>
#	include <stdio.h>
#	include <stdlib.h>
#	include "parsing.h"
#	include <math.h>
#	include <string.h>

#	define EQUAL 0

#	define RIGHT_M 2
#	define LEFT_M 0
#	define DOWN_M 1
#	define UP_M 13
#	define RIGHT_R 124
#	define LEFT_R 123
#	define ESC_KEY 53
#	define WIN_CLOSE 17

#	define FLOOR "F"
#	define CEILLING "C"
#	define TEX_SIZE 64
#	define TILE_SIZE 6
#	define MOUSE_SENSITIVITY 0.5

typedef struct s_image
{
	void	*ptr;
	int		*pixels;
	int		bpp;
	int		endian;
	int		line_len;
}				t_image;

typedef struct s_textures
{
	int	*north;
	int	*south;
	int	*east;
	int	*west;
}				t_textures;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_datas
{
	void		*mlx;
	void		*mlx_win;
	t_image		image;
	t_map		*map;
	t_textures	textures;

	int		x;
	int		screen_h;
	int		screen_w;

	/*----- raycasting variables*/
	double		x_dir;
	double		y_dir;
	double		pos_x;
	double		pos_y;
	double		x_plane;
	double		y_plane;
	double		camera_x;
	double		x_raydir;
	double		y_raydir;
	double		perp_dist_wall;
	double		delta_x_dist;
	double		delta_y_dist;
	double		side_x_dist;
	double		side_y_dist;
	int			x_step;
	int			y_step;
	int			hit_wall;
	int			side;
	int			map_x;
	int			map_y;
	int			draw_start;
	int			draw_end;
	int			line_height;
	double		movespeed;
	double		rote_angle;
	int			rot_right;
	int			rot_left;
	int			move_right;
	int			move_left;
	int			move_up;
	int			move_down;

	/*----- textures*/
	double	wallX;
	double	step;
	double	texPos;
	int		texX;
	int		texY;
} t_datas;

/* ---- Init Functions ---- */
void	init_maps(t_map *map);
void	init_game(t_datas *game);
void	start_game(t_datas *game);

int		ft_close_win(t_datas *data);
void	ft_free(t_datas *data, char *msg);

void	ft_new_window(t_datas *game);
int		rgb_to_int(int color);

int		launch_game(void *ptr);

/*--------- KEY HOOK FUNCTIONS -------*/
int		key_pressed(int key, t_datas *data);
int		key_released(int key, t_datas *data);
void	moves(t_datas *game);

/*------ raycasting fucntions -----*/
void	init_ray_distance(t_datas *data);
void	raycasting(t_datas *data);
void	calc_wall_height(t_datas *data);
void	drawing(t_datas *game);

/*-------- player movements -------*/
void	move_forword(t_datas *game);
void	move_backword(t_datas *game);
void	move_left(t_datas *game);
void	move_right(t_datas *game);
void	rotate(t_datas *game, double angle);
int		ft_mouse(int x, int y, t_datas *vars);

void	draw_mini_map(t_datas *game);

#endif