/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:25:44 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/26 17:11:31 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define INVALID_ARG "Invalid number of arguments!\n"
# define MALLOC_ERR "Failed to allocate memory!\n"
# define OPEN_ERR "Failed to open file!\n"
# define FILENAME_ERR "File name not formatted correctly!\nFile name : *.cub\n"
# define COLOR_ERR "Color not in right format!\n"
# define MAP_ERR "Map not in right format!\n"
# define CUB_ERR ".cub file not in right format!\n"
# define MANY_PLAYERS "Too many players in the map!\n"
# define NO_PLAYER "No player in the map!\n"
# define PATH_EXTENSION "Path to texture not a xpm file!\n"
# define LINE_UNEXPECTED "Line unexpected in file!\n"
# define EMPTY_LINE_IN_MAP "Map cannot have an empty line!\n"
# define LEFT_EDGE "Player or 0 on left edge!\n"
# define RIGHT_EDGE "Player or 0 on right edge!\n"
# define TOP_EDGE "Player or 0 on top edge!\n"
# define BOTTOM_EDGE "Player or 0 on bottom edge!\n"
# define CHAR_UNEXPECTED "Character unexpected in map!\n"
# define MLX_ERR "Failed to initialize connection!\n"
# define MLX_WINDOW_ERR "Failed to create window!\n"
# define MLX_IMAGE_ERR "Failed to create new image!\n"
# define MLX_IMAGE_DATA_ERR "Failed to get image data!\n"

#endif