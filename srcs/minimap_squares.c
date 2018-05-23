/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_squares.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvautrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:37:39 by cvautrai          #+#    #+#             */
/*   Updated: 2018/03/08 13:16:13 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_square(char *img_str, t_vect_d2 pos, t_vect_d3 color)
{
	int		i;
	int		j;
	int		len;

	len = 5;
	j = -len;
	pos.x -= len;
	pos.y -= len;
	while (j < len)
	{
		i = -len;
		while (i < len)
		{
			ft_fill_pixel(img_str, 150, pos, color);
			pos.x++;
			i++;
		}
		pos.x -= 2 * len;
		pos.y++;
		j++;
	}
}

static void	alpha_px(char *img_str, t_vect_d2 pos, t_vect_d4 a)
{
	int		r;

	if (pos.x >= 0 && pos.x < 150 && pos.y >= 0 && pos.y < 150)
	{
		r = (int)pos.x * 4 + (int)pos.y * 4 * 150;
		img_str[r] = a.x;
		img_str[r + 1] = a.y;
		img_str[r + 2] = a.z;
		img_str[r + 3] = a.w;
	}
}

void		alpha_square(char *img_str, t_vect_d2 pos, t_vect_d4 color)
{
	int		i;
	int		j;
	int		len;

	len = 5;
	j = -len;
	pos.x -= len;
	pos.y -= len;
	while (j < len)
	{
		i = -len;
		while (i < len)
		{
			alpha_px(img_str, pos, color);
			pos.x++;
			i++;
		}
		pos.x -= 2 * len;
		pos.y++;
		j++;
	}
}

static void	circle_line(int i, char *img_str, t_vect_d2 pos, t_vect_d3 color)
{
	int		lim;

	lim = -i - 1;
	pos.x += i;
	while (i <= lim)
	{
		ft_fill_pixel(img_str, 150, pos, color);
		i++;
		pos.x++;
	}
}

void		draw_circle(char *img_str, t_vect_d2 pos, t_vect_d3 color)
{
	int		j;

	j = -4;
	pos.y += j;
	circle_line(-2, img_str, pos, color);
	pos.y++;
	circle_line(-3, img_str, pos, color);
	pos.y++;
	circle_line(-4, img_str, pos, color);
	pos.y++;
	circle_line(-4, img_str, pos, color);
	pos.y++;
	circle_line(-4, img_str, pos, color);
	pos.y++;
	circle_line(-4, img_str, pos, color);
	pos.y++;
	circle_line(-3, img_str, pos, color);
	pos.y++;
	circle_line(-2, img_str, pos, color);
}
