/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_seg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 00:07:21 by bspindle          #+#    #+#             */
/*   Updated: 2018/01/16 13:21:37 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_put_seg(t_data *data, t_seg_d2 seg, t_vect_d3 color)
{
	double		lambda;
	t_vect_d2	m;

	lambda = 0;
	while (lambda <= 1)
	{
		m.x = (int)(seg.a.x * lambda + (1 - lambda) * seg.b.x);
		m.y = (int)(seg.a.y * lambda + (1 - lambda) * seg.b.y);
		ft_fill_pixel(data->image_str, data->size_line, m, color);
		lambda += 0.005;
	}
}
