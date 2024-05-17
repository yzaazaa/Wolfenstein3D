/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:19:50 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/17 15:11:51 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Function that gets the red part of the color

int	get_r(int rgb)
{
	return ((rgb >> 16) & 0xFF);
}

// Function that gets the green part of the color

int	get_g(int rgb)
{
	return ((rgb >> 8) & 0xFF);
}

// Function that gets the blue part of the color

int	get_b(int rgb)
{
	return (rgb & 0xFF);
}
