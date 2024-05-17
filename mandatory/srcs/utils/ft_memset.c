/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:54:55 by Razog             #+#    #+#             */
/*   Updated: 2024/05/17 15:55:00 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bytes;
	size_t			i;

	bytes = (unsigned char *)b;
	i = 0;
	while (i < len)
		bytes[i++] = (unsigned char)c;
	return (b);
}
