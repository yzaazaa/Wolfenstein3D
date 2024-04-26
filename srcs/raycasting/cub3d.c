/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:07:48 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/26 05:21:08 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_free(t_datas *data, char *msg)
{
    mlx_destroy_window(data->mlx, data->mlx_win);
    printf("%s", msg);
    exit(EXIT_SUCCESS);
}
int ft_close_win(t_datas *data)
{
    ft_free(data, "WINDOW CLOSED\n");
    return (0);
}


void	init_map(t_map *map)
{
    map->map2d = NULL;
    map->north_texture = NULL;
    map->south_texture = NULL;
    map->east_texture = NULL;
    map->west_texture = NULL;
}

void    init_game(t_datas *game)
{
    init_map(&game->map);
    game->mlx = mlx_init();
    game->screen_h = 1024;
    game->screen_w = 1024;
    game->x = 0;
    game->pos_x = 0;
    game->pos_y = 0;
    game->mlx_win = mlx_new_window(game->mlx, game->screen_w, game->screen_h, "cub3D");
}


int	lunch_game(void)
{
	t_datas	data;
    
    init_game(&data);
	mlx_clear_window(data.mlx, data.mlx_win);
	//draw(&data);
    mlx_hook(data.mlx_win, WIN_CLOSE, 0, ft_close_win, &data);
    mlx_hook(data.mlx_win, 2, 0, &key_pressed, &data);
    mlx_hook(data.mlx_win, 3, 0, &key_released, &data);
    mlx_loop(data.mlx);
	return (0);
}
