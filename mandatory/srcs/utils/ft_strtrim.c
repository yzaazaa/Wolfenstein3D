/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:16:13 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:16:09 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strtrim_free(char const *s1, char const *set)
{
	char	*trimmed;
	int		i;
	int		start;

	if (!s1 || !set)
		return (NULL);
	if (!s1[0])
		return (ft_strdup(""));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = i;
	trimmed = ft_substr(s1, start, ft_strlen(s1));
	if (!trimmed)
		return (NULL);
	free((void *)s1);
	return (trimmed);
}
