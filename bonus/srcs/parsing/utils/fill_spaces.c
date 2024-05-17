/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:44:22 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/17 16:52:58 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

// Function that gets the len of the biggest string

int	len_biggest_str(t_list *raw_map)
{
	t_node	*current;
	int		len;
	int		len_current;

	current = raw_map->head;
	len = ft_strlen((char *)current->data);
	current = current->next;
	while (current)
	{
		len_current = ft_strlen((char *)current->data);
		if (len < len_current)
			len = len_current;
		current = current->next;
	}
	return (len);
}

// Function that fills spaces at the end of each line

void	fill_spaces(t_list *raw_map, t_map *map)
{
	t_node	*current;
	int		len;
	char	*old_line;
	char	*line;
	int		i;

	len = len_biggest_str(raw_map);
	current = raw_map->head;
	while (current)
	{
		old_line = current->data;
		line = malloc(len + 1);
		if (!line)
			puterr(MALLOC_ERR, NULL, map);
		i = ft_strlen(old_line);
		line = ft_memcpy(line, old_line, i);
		while (i < len)
			line[i++] = ' ';
		line[len] = '\0';
		current->data = line;
		free(old_line);
		current = current->next;
	}
}
