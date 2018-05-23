/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:03:06 by bspindle          #+#    #+#             */
/*   Updated: 2018/01/12 11:20:18 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vect_d2	ft_vd2_new(double x, double y)
{
	t_vect_d2	a;

	a.x = x;
	a.y = y;
	return (a);
}

t_vect_d3	ft_vd3_new(double x, double y, double z)
{
	t_vect_d3	a;

	a.x = x;
	a.y = y;
	a.z = z;
	return (a);
}
