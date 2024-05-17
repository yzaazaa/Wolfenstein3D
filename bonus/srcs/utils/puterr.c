/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:25:52 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/17 16:54:34 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Function that prints an error message and exits the program

void	puterr(char *s, t_datas *game, t_map *map)
{
	printf("Error\n");
	if (s)
		printf("%s", s);
	if (map)
		free_map(map);
	if (game)
		ft_free(game, NULL);
	exit(1);
}
