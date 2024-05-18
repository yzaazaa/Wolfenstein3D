/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:11:59 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/05/18 17:12:01 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

// Function that check the file name

void	check_file_name(char *cub_file)
{
	int	len_file;

	len_file = ft_strlen(cub_file);
	if (len_file < 4 || ft_strcmp(cub_file + len_file - 4, ".cub"))
		puterr(FILENAME_ERR, NULL, NULL);
}
