/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_vector_prod.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 08:11:47 by bspindle          #+#    #+#             */
/*   Updated: 2018/01/12 17:17:56 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vect_d2	ft_product_d2(t_vect_d2 a, t_22_matrix m)
{
	t_vect_d2	b;

	b.x = m.a[0][0] * a.x + m.a[0][1] * a.y;
	b.y = m.a[1][0] * a.x + m.a[1][1] * a.y;
	return (b);
}

t_vect_d3	ft_product_d3(t_vect_d3 a, t_33_matrix m)
{
	t_vect_d3	b;

	b.x = m.a[0][0] * a.x + m.a[0][1] * a.y + m.a[0][2] * a.z;
	b.y = m.a[1][0] * a.x + m.a[1][1] * a.y + m.a[1][2] * a.z;
	b.z = m.a[2][0] * a.x + m.a[2][1] * a.y + m.a[2][2] * a.z;
	return (b);
}

t_vect_d2	ft_product_32m(t_vect_d3 a, t_32_matrix m)
{
	t_vect_d2	b;

	b.x = m.a[0][0] * a.x + m.a[0][1] * a.y + m.a[0][2] * a.z;
	b.y = m.a[1][0] * a.x + m.a[1][1] * a.y + m.a[1][2] * a.z;
	return (b);
}
