/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:25:44 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 13:17:22 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

// Function that checks the path to texture

static void	check_path(char *texture, t_map *map)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd == -1)
		puterr(OPEN_ERR, NULL, map);
	close(fd);
}

// Function that gets path to texture

char	*get_texture(t_map *map, char *line)
{
	char		*texture;
	int			i;
	int			len;
	int			j;

	i = 2;
	if (map == NULL)
		puterr(MALLOC_ERR, NULL, NULL);
	while (!(line[i] > ' ' && line[i] < 127))
		i++;
	len = 0;
	while (line[i + len])
		len++;
	texture = malloc(len + 1);
	if (!texture)
		puterr(MALLOC_ERR, NULL, map);
	j = 0;
	while (j < len)
		texture[j++] = line[i++];
	texture[j] = '\0';
	check_path(texture, map);
	return (texture);
}
