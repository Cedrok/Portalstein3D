/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 22:10:34 by bspindle          #+#    #+#             */
/*   Updated: 2018/02/28 13:13:03 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_H
# define LIBGRAPH_H
# include "../minilibx_macos/mlx.h"
# include "math.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define WIN_LENGTH 900
# define WIN_HIGH 700

typedef struct		s_vect_d2

{
	double			x;
	double			y;
}					t_vect_d2;

typedef struct		s_vect_d3
{
	double			x;
	double			y;
	double			z;
}					t_vect_d3;

typedef struct		s_vect_d4
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vect_d4;

typedef struct		s_base_d3
{
	t_vect_d3		center;
	t_vect_d3		x_axis;
	t_vect_d3		y_axis;
	t_vect_d3		z_axis;
}					t_base_d3;

typedef struct		s_base_d2
{
	t_vect_d2		center;
	t_vect_d2		x_axis;
	t_vect_d2		y_axis;
}					t_base_d2;

typedef struct		s_half_right_d3
{
	t_vect_d3		end;
	t_vect_d3		direction;
}					t_half_right_d3;

typedef struct		s_half_right_d2
{
	t_vect_d2		end;
	t_vect_d2		direction;
}					t_half_right_d2;

typedef struct		s_seg_d3
{
	t_vect_d3		a;
	t_vect_d3		b;
}					t_seg_d3;

typedef struct		s_seg_d2
{
	t_vect_d2		a;
	t_vect_d2		b;
}					t_seg_d2;

typedef struct		s_data
{
	void			*mlx;
	void			*window;
	void			*image;
	char			*image_str;
	int				bpp;
	int				size_line;
	int				endian;
}					t_data;

typedef	struct		s_22_matrix
{
	double			a[2][2];
}					t_22_matrix;

typedef struct		s_33_matrix
{
	double			a[3][3];
}					t_33_matrix;

typedef struct		s_32_matrix
{
	double			a[2][3];
}					t_32_matrix;

t_base_d3			*ft_base_d3_new(t_vect_d3 c, t_vect_d3 x, t_vect_d3 y,
		t_vect_d3 z);
t_vect_d2			ft_vd2_new(double x, double y);
t_vect_d2			ft_product_d2(t_vect_d2 a, t_22_matrix m);
t_vect_d2			ft_vd2_sum(t_vect_d2 a, t_vect_d2 b);
t_vect_d2			ft_product_32m(t_vect_d3 a, t_32_matrix m);
t_vect_d2			lambda_product_d2(double lambda, t_vect_d2 vect);
t_seg_d3			ft_new_seg_d3(t_vect_d3 a, t_vect_d3 b);
t_vect_d3			ft_vd3_sum(t_vect_d3 a, t_vect_d3 b);
t_seg_d2			ft_new_seg_d2(t_vect_d2 a, t_vect_d2 b);
t_vect_d3			ft_zoom_point(t_vect_d3 a, double x);
t_vect_d3			ft_zoom_point_z(t_vect_d3 a, double x);
t_vect_d3			ft_vd3_new(double x, double y, double z);
t_vect_d3			ft_product_d3(t_vect_d3 a, t_33_matrix m);
t_vect_d3			lambda_product_d3(double lambda, t_vect_d3 vect);
void				ft_clear_image(t_data *data);
void				ft_put_seg(t_data *data, t_seg_d2 s, t_vect_d3 c);
void				ft_put_half_right(t_data *data, t_half_right_d2 hr,
		t_vect_d3 colour);
void				ft_fill_pixel(char *image_str, int size_line,
		t_vect_d2 pos, t_vect_d3 colour);
t_vect_d4			ft_vd4_new(double x, double y, double z, double w);
int					ft_clean_image(int k, void *param);
t_data				*ft_new_data(int size_x, int size_y, char *window_name);
void				ft_add_pixel(char *image_str, int size_line,
		t_vect_d2 p, t_vect_d3 c);
void				ft_free_data(t_data **data);
double				distance_d2(t_vect_d2 a, t_vect_d2 b);

#endif
