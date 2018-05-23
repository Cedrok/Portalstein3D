/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:57:09 by bspindle          #+#    #+#             */
/*   Updated: 2018/02/28 09:08:18 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_fill_pixel(char *image_str, int size_line, t_vect_d2 pos,
		t_vect_d3 colour)
{
	int	r;

	if (pos.x >= 0 && pos.x < size_line && pos.y >= 0 && pos.y < WIN_HIGH)
	{
		r = (int)pos.x * 4 + (int)pos.y * 4 * size_line;
		image_str[r] = colour.x;
		image_str[r + 1] = colour.y;
		image_str[r + 2] = colour.z;
	}
}

void	ft_add_pixel(char *image_str, int size_line, t_vect_d2 pos,
		t_vect_d3 colour)
{
	int	r;

	if (pos.x >= 0 && pos.x < size_line && pos.y >= 0 && pos.y < WIN_HIGH)
	{
		r = (int)pos.x * 4 + (int)pos.y * 4 * size_line;
		image_str[r] += colour.x;
		image_str[r + 1] += colour.y;
		image_str[r + 2] += colour.z;
	}
}
