/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:38:07 by lseema            #+#    #+#             */
/*   Updated: 2020/02/07 20:38:12 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	three_d(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.523599);
	*y = (*x + *y) * sin(0.523599) - z;
}

void	rotate_x(float *y, float *z, int angle)
{
	double	radian;
	float	temp_y;

	temp_y = *y;
	radian = (double)(angle * 3.14 / 180);
	*y = temp_y * cos(radian) + *z * sin(radian);
	*z = -temp_y * sin(radian) + *z * cos(radian);
}

void	rotate_y(float *x, float *z, int angle)
{
	double	radian;
	float	temp_x;

	temp_x = *x;
	radian = (double)(angle * 3.14) / (double)180;
	*x = temp_x * cos(radian) + *z * sin(radian);
	*z = -temp_x * sin(radian) + *z * cos(radian);
}

void	rotate_z(float *x, float *y, int angle)
{
	float	temp_x;
	float	temp_y;
	double	radian;

	temp_x = *x;
	temp_y = *y;
	radian = (double)(angle * 3.14) / (double)180;
	*x = temp_x * cos(radian) - temp_y * sin(radian);
	*y = temp_y * sin(radian) + temp_y * cos(radian);
}

void	translation_xyz(t_point *p1, t_point *p2, t_struct *data)
{
	rotate_x(&p1->y, &p1->z, data->x_ang);
	rotate_x(&p2->y, &p2->z, data->x_ang);
	rotate_y(&p1->x, &p1->z, data->y_ang);
	rotate_y(&p2->x, &p2->z, data->y_ang);
	rotate_z(&p1->x, &p1->y, data->z_ang);
	rotate_z(&p2->x, &p2->y, data->z_ang);
	p1->x *= data->zoom;
	p1->y *= data->zoom;
	p1->z *= data->zoom;
	p2->x *= data->zoom;
	p2->y *= data->zoom;
	p2->z *= data->zoom;
	p1->x += data->x_shift;
	p1->y += data->y_shift;
	p2->x += data->x_shift;
	p2->y += data->y_shift;
	if (data->is_isometric)
	{
		three_d(&p1->x, &p1->y, p1->z);
		three_d(&p2->x, &p2->y, p2->z);
	}
}
