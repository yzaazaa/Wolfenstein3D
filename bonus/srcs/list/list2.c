/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:15:48 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/17 16:52:49 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"
#include "error_bonus.h"

char	**list_to_array(t_list *list, t_map *map)
{
	char	**ret;
	t_node	*tmp;
	int		i;

	ret = malloc(sizeof(char *) * (list->size + 1));
	if (!ret)
		puterr(MALLOC_ERR, NULL, map);
	i = 0;
	tmp = list->head;
	while (tmp)
	{
		ret[i] = ft_strdup((char *)tmp->data);
		if (!ret[i++])
			puterr(MALLOC_ERR, NULL, map);
		tmp = tmp->next;
	}
	ret[i] = NULL;
	return (ret);
}
