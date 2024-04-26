/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:42:46 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/26 10:52:36 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// void f(){system("leaks cub3d");}
int	main(int ac, char **av)
{
	// atexit(f);
	t_map	*map;
	t_datas	*data;

	if (ac != 2)
		puterr(INVALID_ARG);
	map = parse_map(av[1]);
	data = malloc(sizeof(t_datas));
	if (!data)
		puterr(MALLOC_ERR);
	data->map = map;
	data->pos_x = map->pos_x;
	data->pos_y = map->pos_y;
	launch_game(data);
	free_map(map);
	free(data);
	return (0);
}
