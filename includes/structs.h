/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:28:21 by Razog             #+#    #+#             */
/*   Updated: 2024/05/18 12:39:43 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_node
{
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		size;
}				t_list;

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_map
{
	t_list				*map_content;
	char				**map2d;
	char				spawn_orientation;
	char				*north_texture;
	char				*south_texture;
	char				*west_texture;
	char				*east_texture;
	int					row;
	int					col;
	t_vector			player;
	int					floor_color;
	int					ceilling_color;
}				t_map;

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
	t_image	north;
	t_image	south;
	t_image	east;
	t_image	west;
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

	int			x;
	int			screen_h;
	int			screen_w;

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
	double		wallx;
	double		step;
	double		texpos;
	int			tex_x;
	int			tex_y;
}			t_datas;

#endif