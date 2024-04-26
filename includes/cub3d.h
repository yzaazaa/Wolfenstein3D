/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:14:08 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/26 05:19:04 by frukundo         ###   ########.fr       */
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

#	define KEY_A 0
#	define KEY_S 1
#	define KEY_D 2
#	define KEY_W 13
#	define WIN_CLOSE 17
#	define ESC_KEY 53
#	define KEY_LEFT 123
#	define KEY_RIGHT 124


typedef struct s_datas
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	int		right_key_presed;
	int		left_key_pressed;
	int		w_key_pressed;
	int		s_key_pressed;
	int		a_key_pressed;
	int		d_key_pressed;



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

	
} t_datas;

int ft_close_win(t_datas *data);
void ft_free(t_datas *data, char *msg);

/*--------- KEY HOOK FUNCTIONS -------*/
int key_pressed(int key, t_datas *data);
int key_released(int key, t_datas *data);

/*------ raycasting fucntions -----*/
void		init_ray_distance(t_datas *data);
void		raycasting(t_datas *data);
void		calc_wall_height(t_datas *data);


#endif