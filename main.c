/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:42:46 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/21 14:01:48 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		puterr(INVALID_ARG);
	map = parse_map(av[1]);
	print_map_content(map);
	free_map(map);
	return (0);
}
