/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:14:08 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/17 20:45:54 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "parsing_bonus.h"
# include <math.h>
# include <string.h>
# include "structs_bonus.h"

# define EQUAL 0

# define RIGHT_M 2
# define LEFT_M 0
# define DOWN_M 1
# define UP_M 13
# define RIGHT_R 124
# define LEFT_R 123
# define ESC_KEY 53
# define WIN_CLOSE 17

# define FLOOR "F"
# define CEILLING "C"
# define TEX_SIZE 64
# define SCREEN_H 1024
# define SCREEN_W 1024

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

void	put_pixel(t_datas *game, int x, int y, int color);
void	draw_crosshair(t_datas *game);

#endif