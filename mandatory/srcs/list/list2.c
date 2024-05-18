/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:15:48 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:14:48 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"

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
