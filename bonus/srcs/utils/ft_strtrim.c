/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:16:13 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 13:23:10 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

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
