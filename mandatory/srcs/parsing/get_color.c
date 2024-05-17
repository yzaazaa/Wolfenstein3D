/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:20:31 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/17 15:02:02 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_color(char *line, int *i, t_map *map)
{
	int	ret;

	ret = ft_atoi(line + *i);
	if (ret < 0 || ret > 255)
		puterr(COLOR_ERR, NULL, map);
	while (ft_isdigit(line[*i]) || line[*i] == '-' || line[*i] == '+')
		(*i)++;
	return (ret);
}

static void	skip_spaces(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

// Function that gets color

int	get_color(char *line, t_map *map)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 1;
	while (line[i] && !ft_isdigit(line[i]) && line[i] != '-' && line[i] != '+')
		i++;
	r = check_color(line, &i, map);
	if (line[i++] != ',')
		puterr(COLOR_ERR, NULL, map);
	skip_spaces(line, &i);
	if (!ft_isdigit(line[i]))
		puterr(COLOR_ERR, NULL, map);
	g = check_color(line, &i, map);
	if (line[i++] != ',')
		puterr(COLOR_ERR, NULL, map);
	skip_spaces(line, &i);
	if (!ft_isdigit(line[i]))
		puterr(COLOR_ERR, NULL, map);
	b = check_color(line, &i, map);
	if (line[i])
		puterr(COLOR_ERR, NULL, map);
	return ((r << 16) + (g << 8) + b);
}
