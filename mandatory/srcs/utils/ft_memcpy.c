/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 02:23:37 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:15:31 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*source;

	i = 0;
	if (!dst && !src)
		return (NULL);
	dest = (char *)dst;
	source = (const char *)src;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
