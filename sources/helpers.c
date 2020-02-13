/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:38:55 by lseema            #+#    #+#             */
/*   Updated: 2020/02/08 21:21:58 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *msg)
{
	ft_putstr(msg);
	exit(0);
}

void	free_and_exit(char *msg, t_struct *data)
{
	free(data);
	error(msg);
}

void	set_extremums(t_struct *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->max_z = data->matrix[i][j];
	data->min_z = data->matrix[i][j];
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->matrix[i][j] > data->max_z)
				data->max_z = data->matrix[i][j];
			if (data->matrix[i][j] < data->min_z)
				data->min_z = data->matrix[i][j];
			j++;
		}
		i++;
	}
}

void	set_start_settings(t_struct *data)
{
	set_extremums(data);
	data->s_color = 0x008000;
	data->e_color = 0x800080;
	data->is_isometric = 0;
	data->is_hide = 1;
	data->x_ang = 0;
	data->y_ang = 0;
	data->z_ang = 0;
	data->x_shift = 400;
	data->y_shift = 400;
	data->zoom = 30;
}

void	initialize(char *arg, t_struct *data)
{
	if (open(arg, O_DIRECTORY) >= 0)
		free_and_exit("FOLDERS NOT ALLOWED\n", data);
	if (!set_size(data, arg))
		free_and_exit("INVALID SIZE\n", data);
	if (!allocate_matrix(data))
		free_and_exit("MEMORY NOT ALLOCATED\n", data);
	if (!read_file(arg, data))
	{
		free_arr(data);
		free_and_exit("INVALID MAP\n", data);
	}
	if (!(data->mlx_ptr = mlx_init()))
	{
		free_arr(data);
		free_and_exit("ERROR ON MINILIBX INIT\n", data);
	}
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr,
					WINWIDTH, WINWIDTH, "FDF")))
	{
		free_arr(data);
		free_and_exit("ERROR ON MLX_WINDOW CREATE\n", data);
	}
	set_start_settings(data);
}
