/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Razog <yassine.zaaaza@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:25:46 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/17 15:11:20 by Razog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parsing.h"

// Function that returns a new list given a generic data

t_list	*new_list(void *data, t_map *map)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		puterr(MALLOC_ERR, NULL, map);
	list->head = malloc(sizeof(t_node));
	if (!list->head)
		puterr(MALLOC_ERR, NULL, map);
	list->tail = list->head;
	list->head->data = data;
	list->head->next = NULL;
	list->head->prev = NULL;
	list->size = 1;
	return (list);
}

// Function that adds a new node at the end of the list

void	add_back_lst(t_list **list, void *data, t_map *map)
{
	t_node	*new_node;
	t_node	*current;

	if (!(*list))
	{
		*list = new_list(data, map);
		return ;
	}
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		puterr(MALLOC_ERR, NULL, map);
	current = (*list)->tail;
	current->next = new_node;
	new_node->prev = current;
	new_node->data = data;
	new_node->next = NULL;
	(*list)->tail = new_node;
	(*list)->size++;
}

// Function that removes a given node in the linked list

void	remove_node_list(t_list *list, t_node *node_to_delete)
{
	if (list->head == node_to_delete && list->tail == node_to_delete)
	{
		free_list(&list);
		return ;
	}
	if (list->head == node_to_delete)
		list->head = list->head->next;
	if (list->tail == node_to_delete)
		list->tail = list->tail->prev;
	if (node_to_delete->next)
		node_to_delete->next->prev = node_to_delete->prev;
	if (node_to_delete->prev)
		node_to_delete->prev->next = node_to_delete->next;
	list->size--;
	free(node_to_delete->data);
	free(node_to_delete);
}

// Function that frees the list

void	free_list(t_list **list)
{
	t_node	*current;
	t_node	*node_to_delete;

	current = (*list)->head;
	while (current)
	{
		node_to_delete = current;
		current = current->next;
		free(node_to_delete->data);
		free(node_to_delete);
	}
	free(*list);
	*list = NULL;
}
