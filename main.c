/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:42:46 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/24 17:32:33 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"
// void f(){system("leaks cub3d");}
int	main(int ac, char **av)
{
	// atexit(f);
	t_map	*map;

	if (ac != 2)
		puterr(INVALID_ARG);
	map = parse_map(av[1]);
	print_map_content(map);
	free_map(map);
	return (0);
}
