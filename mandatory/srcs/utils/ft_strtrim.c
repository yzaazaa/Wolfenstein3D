/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:16:13 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/17 15:44:02 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strtrim_free(char const *s1, char const *set)
{
	char	*trimmed;
	int		i;
	int		start;
	int		len_trimmed;

	if (!s1 || !set)
		return (NULL);
	if (!s1[0])
		return (ft_strdup(""));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i--;
	len_trimmed = i - start + 1;
	trimmed = ft_substr(s1, start, len_trimmed);
	if (!trimmed)
		return (NULL);
	free((void *)s1);
	return (trimmed);
}
