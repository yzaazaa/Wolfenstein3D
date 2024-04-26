/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 01:54:55 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/25 08:24:07 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int key_pressed(int key, t_datas *data)
{
    if (key == ESC_KEY)
        ft_close_win(data);
    else if(key == KEY_W)
        data->w_key_pressed = 1;
    else if(key == KEY_S)
        data->s_key_pressed = 1;
    else if(key == KEY_A)
        data->a_key_pressed = 1;
    else if(key == KEY_D)
        data->d_key_pressed = 1;
    else if(key == KEY_LEFT)
        data->left_key_pressed = 1;
    else if(key == KEY_RIGHT)
        data->right_key_presed = 1;
    else
        return (1);
    return (0);
}

int key_released(int key, t_datas *data)
{
    if(key == KEY_W)
        data->w_key_pressed = 0;
    else if(key == KEY_S)
        data->s_key_pressed = 0;
    else if(key == KEY_A)
        data->a_key_pressed = 0;
    else if(key == KEY_D)
        data->d_key_pressed = 0;
    else if(key == KEY_LEFT)
        data->left_key_pressed = 0;
    else if(key == KEY_RIGHT)
        data->right_key_presed = 0;
    return (0);
}
