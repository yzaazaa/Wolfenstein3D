/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:25:50 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:28:12 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <limits.h>
# include "error_bonus.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include "structs_bonus.h"

/*		utils		*/

void	*ft_memset(void *b, int c, size_t len);
void	puterr(char *s, t_datas *game, t_map *map);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char const *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim_free(char const *s1, char const *set);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(char *s1);
int		is_empty_line(char *str);
void	free_array(char **array);

/*		list		*/
t_list	*new_list(void *data, t_map *map);
void	add_back_lst(t_list **list, void *data, t_map *map);
char	**list_to_array(t_list *list, t_map *map);
void	free_list(t_list **list);
void	remove_node_list(t_list *list, t_node *node_to_delete);

/*		parsing		*/
void	check_file_name(char *cub_file);
t_list	*get_raw_map(char *cub_file, t_map *map);
int		get_color(char *line, t_map *map);
char	*get_texture(t_map *map, char *line);
int		is_player_spawn(char c);
int		len_biggest_str(t_list *raw_map);
void	fill_spaces(t_list *raw_map, t_map *map);
void	check_map(t_map *map);
void	get_map_info(t_map *map, t_list *raw_map);
void	parse_map(t_map *map, char *cub_file);
void	free_map(t_map *map);

#endif