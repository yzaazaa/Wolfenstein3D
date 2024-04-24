/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:20:31 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/09 04:24:26 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	check_color(char *line, int *i)
{
	int	ret;

	ret = ft_atoi(line + *i);
	if (ret < 0 || ret > 255)
		puterr(COLOR_ERR);
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

int	get_color(char *line)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 1;
	while (line[i] && !ft_isdigit(line[i]) && line[i] != '-' && line[i] != '+')
		i++;
	r = check_color(line, &i);
	if (line[i++] != ',')
		puterr(COLOR_ERR);
	skip_spaces(line, &i);
	if (!ft_isdigit(line[i]))
		puterr(COLOR_ERR);
	g = check_color(line, &i);
	if (line[i++] != ',')
		puterr(COLOR_ERR);
	skip_spaces(line, &i);
	if (!ft_isdigit(line[i]))
		puterr(COLOR_ERR);
	b = check_color(line, &i);
	if (line[i])
		puterr(COLOR_ERR);
	return ((r << 16) + (g << 8) + b);
}
