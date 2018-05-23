/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_half_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:51:26 by bspindle          #+#    #+#             */
/*   Updated: 2018/01/12 15:14:47 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_put_half_right(t_data *data, t_half_right_d2 half_right,
		t_vect_d3 colour)
{
	double		k;
	t_vect_d2	to_fill;

	k = 0;
	while (k < 700)
	{
		to_fill = ft_vd2_sum(half_right.end,
				lambda_product_d2(k, half_right.direction));
		ft_fill_pixel(data->image_str, data->size_line, to_fill, colour);
		k += 0.05;
	}
}
