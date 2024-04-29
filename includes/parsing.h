/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:25:50 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/29 17:45:50 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "list.h"
# include "error.h"
# include "utils.h"
# include "../srcs/gnl/get_next_line.h"
# include <fcntl.h>

typedef struct s_vector
{
	int x;
	int y;
} t_vector;

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
	int					max_y;
	int					max_x;
	t_vector			player;
	int					floor_color;
	int					ceilling_color;
	char				*filename;
	char				starting_pos;
}				t_map;



void	print_map_content(t_map *map);
void	check_file_name(char *cub_file);
t_list	*get_raw_map(char *cub_file);
int		get_color(char *line);
char	*get_texture(t_map *map, char *line);
int		is_player_spawn(char c);
int		len_biggest_str(t_list *raw_map);
void	fill_spaces(t_list *raw_map);
void	check_map(t_map *map);
void	get_map_info(t_map *map, t_list *raw_map);
t_map	*parse_map(char *cub_file);
void	free_map(t_map *map);

#endif