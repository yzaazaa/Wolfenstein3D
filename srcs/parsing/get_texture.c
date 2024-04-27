/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:25:44 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/27 18:17:29 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <mlx.h>

// Function that checks the path to texture

static void	check_path(char *texture)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd == -1)
		puterr(OPEN_ERR);
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
		puterr(MALLOC_ERR);
	while (!(line[i] > ' ' && line[i] < 127))
		i++;
	len = 0;
	while (line[i + len] > ' ' && line[i + len] < 127)
		len++;
	texture = malloc(len + 1);
	if (!texture)
		puterr(MALLOC_ERR);
	j = 0;
	while (j < len)
		texture[j++] = line[i++];
	texture[j] = '\0';
	check_path(texture);
	return (texture);
}
