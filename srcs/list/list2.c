/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:15:48 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/21 14:23:57 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/error.h"
#include "../../includes/utils.h"

char	**list_to_array(t_list *list)
{
	char	**ret;
	t_node	*tmp;
	int		i;

	ret = malloc(sizeof(char *) * (list->size + 1));
	if (!ret)
		puterr(MALLOC_ERR);
	i = 0;
	tmp = list->head;
	while (tmp)
	{
		ret[i++] = ft_strdup((char *)tmp->data);
		tmp = tmp->next;
	}
	ret[i] = NULL;
	return (ret);
}
