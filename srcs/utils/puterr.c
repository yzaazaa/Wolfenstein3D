/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:25:52 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/09 04:25:01 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

// Function that prints an error message and exits the program

void	puterr(char *s)
{
	printf("Error\n");
	if (s)
		printf("%s", s);
	exit(1);
}
