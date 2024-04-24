/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:15:47 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/24 17:22:32 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Function that check the file name

void	check_file_name(char *cub_file)
{
	int	len_file;

	len_file = ft_strlen(cub_file);
	if (len_file < 4 || ft_strcmp(cub_file + len_file - 4, ".cub"))
		puterr(FILENAME_ERR);
}
