/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:42:46 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/03 21:37:27 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// // void f(){system("leaks cub3d");}
// int	main(int ac, char **av)
// {
// 	// atexit(f);
// 	t_map	*map;
// 	t_datas	*data;

// 	if (ac != 2)
// 		puterr(INVALID_ARG);
// 	map = parse_map(av[1]);
// 	data = malloc(sizeof(t_datas));
// 	if (!data)
// 		puterr(MALLOC_ERR);
// 	data->map = map;
// 	data->pos_x = map->pos_x;
// 	data->pos_y = map->pos_y;
// 	launch_game(data);
// 	free_map(map);
// 	free(data);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_datas game;
	t_map	*map;

	if (ac != 2)
		puterr(INVALID_ARG);
	init_game(&game);
	map = parse_map(av[1]);
	game.map = map;
	print_map_content(map);
	start_game(&game);
	mlx_hook(game.mlx_win, 2, 0, &key_pressed, &game);
	mlx_hook(game.mlx_win, 3, 0, &key_released, &game);
	mlx_loop_hook(game.mlx, launch_game, &game);
	mlx_loop(game.mlx);
	free_map(map);
	return (0);
}
