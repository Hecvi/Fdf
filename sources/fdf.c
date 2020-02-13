/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:56:34 by lseema            #+#    #+#             */
/*   Updated: 2020/02/08 20:55:06 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_arr(t_struct *data)
{
	int i;

	i = 0;
	while (i < data->h)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}

int		exit_x(t_struct *data)
{
	if (data)
	{
		free_arr(data);
		free(data);
	}
	exit(1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_struct *data;

	if (argc == 2)
	{
		if (!(data = (t_struct*)malloc(sizeof(t_struct))))
			error("ERROR ON MEMORY ALLOCATE\n");
		initialize(argv[1], data);
		draw_map(0, 0, (t_point){.x = 0, .y = 0, .z = 0}, data);
		mlx_key_hook(data->win_ptr, key_handler, data);
		mlx_hook(data->win_ptr, 17, 1L << 17, exit_x, data);
		mlx_loop(data->mlx_ptr);
		free_arr(data);
		free(data);
	}
	else if (argc > 2)
		error("MANY ARGUMENTS\n");
	else
		error("NO INPUT ARGUMENTS\n");
	return (0);
}
