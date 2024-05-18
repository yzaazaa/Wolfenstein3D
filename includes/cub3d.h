/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:14:08 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/18 21:47:29 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "parsing.h"
# include <math.h>
# include "structs.h"

# define RIGHT_M 2
# define LEFT_M 0
# define DOWN_M 1
# define UP_M 13
# define RIGHT_R 124
# define LEFT_R 123
# define ESC_KEY 53
# define WIN_CLOSE 17
# define TEX_SIZE 64
# define SCREEN_H 1080
# define SCREEN_W 1920

/* ---- init ---- */
void	init_game(t_datas *game);
void	start_game(t_datas *game);
void	ft_new_window(t_datas *game);

/* ---- exit ---- */
int		ft_close_win(t_datas *data);
void	ft_free(t_datas *data, char *msg);

/*--------- events -------*/
int		key_pressed(int key, t_datas *data);
int		key_released(int key, t_datas *data);
void	moves(t_datas *game);

/*------ raycasting -----*/
void	init_ray_distance(t_datas *data);
void	raycasting(t_datas *data);
void	calc_wall_height(t_datas *data);

/*-------- player movements -------*/
void	move_forword(t_datas *game);
void	move_backward(t_datas *game);
void	move_left(t_datas *game);
void	move_right(t_datas *game);
void	rotate(t_datas *game, double angle);

/* ---- draw ---- */
void	load_textures(t_datas *game);
void	put_pixel(t_datas *game, int x, int y, int color);
void	drawing(t_datas *game);

#endif