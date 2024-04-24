/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:25:46 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/09 04:23:54 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/error.h"
#include "../../includes/utils.h"

// Function that returns a new list given a generic data

t_list	*new_list(void *data)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		puterr(MALLOC_ERR);
	list->head = malloc(sizeof(t_node));
	if (!list->head)
		puterr(MALLOC_ERR);
	list->tail = list->head;
	list->head->data = data;
	list->head->next = NULL;
	list->head->prev = NULL;
	list->size = 1;
	return (list);
}

// Function that adds a new node at the end of the list

void	add_back_lst(t_list **list, void *data)
{
	t_node	*new_node;
	t_node	*current;

	if (!(*list))
	{
		*list = new_list(data);
		return ;
	}
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		puterr(MALLOC_ERR);
	current = (*list)->tail;
	current->next = new_node;
	new_node->prev = current;
	new_node->data = data;
	new_node->next = NULL;
	(*list)->tail = new_node;
	(*list)->size++;
}

// Function that prints the list

void	print_list(t_list *list)
{
	t_node	*current;

	current = list->head;
	while (current)
	{
		printf("%s\n", (char *)current->data);
		current = current->next;
	}
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
