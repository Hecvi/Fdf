/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:36:41 by lseema            #+#    #+#             */
/*   Updated: 2020/02/07 21:49:03 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINWIDTH 1000
# define WINHEIGHT 1000
# define ESC 53
# define RIGHT 124
# define LEFT 123
# define DOWN 125
# define UP 126
# define NUMPAD_UP 91
# define NUMPAD_DOWN 84
# define NUMPAD_LEFT 86
# define NUMPAD_RIGHT 88
# define NUMPAD_CENTER 87
# define NUMPAD_PLUS 69
# define NUMPAD_MINUS 78
# define SPACE 49
# define TAB 48
# define C 8
# define WHITE  0xFFFFFF
# define SILVER	0xC0C0C0
# define GRAY	0x808080
# define BLACK	0x000000
# define RED	0xFF0000
# define MAROON	0x800000
# define YELLOW	0xFFFF00
# define OLIVE	0x808000
# define LIME	0x00FF00
# define GREEN	0x008000
# define AQUA	0x00FFFF
# define TEAL	0x008080
# define BLUE	0x0000FF
# define NAVY	0x000080
# define FUCHSIA 0xFF00FF
# define PURPLE	0x800080
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_point;

typedef struct	s_struct
{
	int		w;
	int		h;
	int		**matrix;
	int		zoom;
	int		x_shift;
	int		y_shift;
	int		x_ang;
	int		y_ang;
	int		z_ang;
	int		is_isometric;
	int		is_hide;
	int		s_color;
	int		e_color;
	int		max_z;
	int		min_z;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_struct;

int				read_file(char *name, t_struct *data);
int				ft_wdcounter(char const *str, char c);
int				fill_matrix(int *new_line, char *line);
void			bresenham(t_point p1, t_point p2, t_struct *data);
void			draw_map(int x, int y, t_point p1, t_struct *data);
void			three_d(float *x, float *y, int z);
int				key_handler(int key, t_struct *data);
void			draw_menu(t_struct *data);
void			rotate_x(float *y, float *z, int angle);
void			rotate_y(float *x, float *z, int angle);
void			rotate_z(float *x, float *y, int angle);
void			before_draw(t_struct *data);
int				get_color(t_point current, t_point start, t_point end);
void			set_start_settings(t_struct *data);
void			translation_xyz(t_point *p1, t_point *p2, t_struct *data);
void			set_extremums(t_struct *data);
int				get_color_z(float current, float start, float end,
		t_struct *data);
void			free_arr(t_struct *data);
int				set_size(t_struct *data, char *name);
int				ft_isdigit_base(char c, int base);
int				ft_has_prefix(const char *str, int base);
int				ft_isnumber(char *str, int base);
int				ft_isspace(int c);
int				allocate_matrix(t_struct *data);
void			initialize(char *arg, t_struct *data);
void			free_and_exit(char *msg, t_struct *data);
void			error(char *msg);
int				exit_x(t_struct *data);
void			change_color(t_struct *data);
int				maxi(int a, int b);
void			key_handler2(int key, t_struct *data);

#endif
