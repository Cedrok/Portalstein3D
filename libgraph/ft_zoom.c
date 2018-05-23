/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 04:40:58 by bspindle          #+#    #+#             */
/*   Updated: 2018/01/16 11:06:14 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

static t_33_matrix	ft_create_diag(double x)
{
	t_33_matrix	matrix;

	matrix.a[0][0] = x;
	matrix.a[0][1] = 0;
	matrix.a[0][2] = 0;
	matrix.a[1][0] = 0;
	matrix.a[1][1] = x;
	matrix.a[1][2] = 0;
	matrix.a[2][0] = 0;
	matrix.a[2][1] = 0;
	matrix.a[2][2] = x;
	return (matrix);
}

t_vect_d3			ft_zoom_point(t_vect_d3 a, double x)
{
	t_33_matrix	matrix;
	t_vect_d3	b;

	matrix = ft_create_diag(x);
	b = ft_product_d3(a, matrix);
	return (b);
}

static t_33_matrix	ft_create_zm(double x)
{
	t_33_matrix	matrix;

	matrix.a[0][0] = 1;
	matrix.a[0][1] = 0;
	matrix.a[0][2] = 0;
	matrix.a[1][0] = 0;
	matrix.a[1][1] = 1;
	matrix.a[1][2] = 0;
	matrix.a[2][0] = 0;
	matrix.a[2][1] = 0;
	matrix.a[2][2] = x;
	return (matrix);
}

t_vect_d3			ft_zoom_point_z(t_vect_d3 a, double x)
{
	t_33_matrix	matrix;
	t_vect_d3	b;

	matrix = ft_create_zm(x);
	b = ft_product_d3(a, matrix);
	return (b);
}
