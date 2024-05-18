/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:18:50 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:20:55 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Function that checks if a line is empty

int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ((str[i] >= 0 && str[i] <= 32) || str[i] == 127))
		i++;
	if (str[i])
		return (0);
	return (1);
}
