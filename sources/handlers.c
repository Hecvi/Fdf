/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:38:41 by lseema            #+#    #+#             */
/*   Updated: 2020/02/08 20:53:13 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_handler2(int key, t_struct *data)
{
	if (key == NUMPAD_UP)
		data->x_ang -= 3;
	else if (key == NUMPAD_DOWN)
		data->x_ang += 3;
	else if (key == NUMPAD_LEFT)
		data->y_ang -= 3;
	else if (key == NUMPAD_RIGHT)
		data->y_ang += 3;
	else if (key == NUMPAD_CENTER)
		set_start_settings(data);
	else if (key == DOWN)
		data->y_shift += 20;
	else if (key == UP)
		data->y_shift -= 20;
	else if (key == LEFT)
		data->x_shift -= 20;
	else if (key == RIGHT)
		data->x_shift += 20;
	else if (key == NUMPAD_PLUS)
		data->zoom += 20;
	else if (key == NUMPAD_MINUS)
		data->zoom -= 20;
	else if (key == C)
		change_color(data);
}

int		key_handler(int key, t_struct *data)
{
	if (key == ESC)
		exit_x(data);
	else if (key == SPACE)
		data->is_isometric = data->is_isometric ? 0 : 1;
	else if (key == TAB)
		data->is_hide = data->is_hide ? 0 : 1;
	else if (key == 91 || key == 84 || key == 86 || key == 88 || key == 87 ||
	(key >= 123 && key <= 126) || key == 69 || key == 78 || key == 8)
		key_handler2(key, data);
	else
		return (0);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(0, 0, (t_point){.x = 0, .y = 0, .z = 0}, data);
	draw_menu(data);
	return (0);
}

void	change_color(t_struct *data)
{
	if (data->s_color == WHITE)
	{
		data->s_color = SILVER;
		data->e_color = PURPLE;
	}
	else if (data->s_color == SILVER)
	{
		data->s_color = GRAY;
		data->e_color = FUCHSIA;
	}
	else if (data->s_color == GRAY)
	{
		data->s_color = BLACK;
		data->e_color = NAVY;
	}
	else if (data->s_color == BLACK)
	{
		data->s_color = RED;
		data->e_color = BLUE;
	}
	else
	{
		data->s_color = WHITE;
		data->e_color = LIME;
	}
}
