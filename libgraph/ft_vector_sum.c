/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:34:43 by bspindle          #+#    #+#             */
/*   Updated: 2018/01/16 11:05:21 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vect_d2	ft_vd2_sum(t_vect_d2 a, t_vect_d2 b)
{
	t_vect_d2	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}