/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:25:52 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/24 17:24:05 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Function that prints an error message and exits the program

void	puterr(char *s)
{
	printf("Error\n");
	if (s)
		printf("%s", s);
	exit(1);
}
