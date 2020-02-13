/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:38:26 by lseema            #+#    #+#             */
/*   Updated: 2020/02/09 14:24:21 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_point p1, t_point p2, t_struct *data)
{
	int		max;
	t_point	step;
	t_point	cur;

	p1.color = get_color_z(p1.z, data->min_z, data->max_z, data);
	p2.color = get_color_z(p2.z, data->min_z, data->max_z, data);
	translation_xyz(&p1, &p2, data);
	step = (t_point){.x = p2.x - p1.x, .y = p2.y - p1.y, .z = p2.z - p1.z};
	max = maxi(step.y > 0 ? step.y : -step.y, step.x > 0 ? step.x : -step.x);
	step = (t_point){.x = step.x / max, .y = step.y / max, .z = step.z / max};
	cur = (t_point) {.x = p1.x, .y = p1.y, .z = p1.z, .color = p1.color};
	while ((int)(cur.x - p2.x) || (int)(cur.y - p2.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, cur.x, cur.y,
				get_color(cur, p1, p2));
		cur = (t_point){.x = cur.x + step.x, .y = cur.y + step.y,
			.z = cur.z + step.z};
	}
}

void	draw_map(int x, int y, t_point p1, t_struct *data)
{
	t_point p2;

	before_draw(data);
	while (data->h > y)
	{
		x = 0;
		while (data->w > x)
		{
			p1 = (t_point){.x = x, .y = y, .z = data->matrix[y][x]};
			if (x < data->w - 1)
			{
				p2 = (t_point){.x = x + 1, .y = y, .z = data->matrix[y][x + 1]};
				bresenham(p1, p2, data);
			}
			if (y < data->h - 1)
			{
				p2 = (t_point){.x = x, .y = y + 1, .z = data->matrix[y + 1][x]};
				bresenham(p1, p2, data);
			}
			x++;
		}
		y++;
	}
	draw_menu(data);
}

void	before_draw(t_struct *data)
{
	if (data->x_ang >= 360)
		data->x_ang = 0;
	if (data->x_ang <= -3)
		data->x_ang = 357;
	if (data->y_ang >= 360)
		data->y_ang = 0;
	if (data->y_ang <= -3)
		data->y_ang = 357;
	if (data->z_ang >= 360)
		data->z_ang = 0;
	if (data->z_ang <= -3)
		data->z_ang = 357;
	if (data->zoom >= 210 || data->zoom <= 15)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10,
				140, 0xE85E5E, "ERROR ON MAX/MIN ZOOM!");
		data->zoom = (data->zoom >= 210) ? 210 : 15;
	}
	if (data->zoom >= 100 && (data->h >= 35 || data->w >= 35))
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10,
				140, 0xE85E5E, "ERROR ON MAX/MIN ZOOM!");
		data->zoom = 100;
	}
}

void	draw_menu(t_struct *data)
{
	if (data->is_hide)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 5, 0xE85E5E,
				"Move: UP DOWN LEFT RIGHT");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0x03fc35,
				"Mode: SPACE");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 35, 0x03fc35,
				"Zoom: +, -");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0x03fc35,
				"Rotate: 2 8 4 6");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 65, 0x03fc35,
				"Hide: TAB");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 80, 0x03fc35,
				"Color: C");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 95, 0x03fc35,
				"Exit: ESC");
	}
}

int		maxi(int a, int b)
{
	return (a > b ? a : b);
}
