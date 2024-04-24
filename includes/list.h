/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:25:41 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/21 14:24:05 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

// Implementing a generic doubly linked list

typedef struct s_node
{
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		size;
}				t_list;

t_list	*new_list(void *data);
void	add_back_lst(t_list **list, void *data);
void	print_list(t_list *list);
char	**list_to_array(t_list *list);
void	free_list(t_list **list);
void	remove_node_list(t_list *list, t_node *node_to_delete);

#endif