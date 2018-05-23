/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_seg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:41:05 by bspindle          #+#    #+#             */
/*   Updated: 2018/01/13 18:56:51 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_seg_d2	ft_new_seg_d2(t_vect_d2 a, t_vect_d2 b)
{
	t_seg_d2	seg;

	seg.a = a;
	seg.b = b;
	return (seg);
}

t_seg_d3	ft_new_seg_d3(t_vect_d3 a, t_vect_d3 b)
{
	t_seg_d3	seg;

	seg.a = a;
	seg.b = b;
	return (seg);
}
