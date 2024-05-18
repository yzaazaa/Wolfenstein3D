/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:12:53 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:12:55 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

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
