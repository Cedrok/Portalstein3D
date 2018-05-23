/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall_texture_ew.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:45:48 by bspindle          #+#    #+#             */
/*   Updated: 2018/02/27 17:05:30 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_vect_d3	texture_color_e(int x, int y, t_texture wall)
{
	int			i;
	t_vect_d3	color;

	i = (x + y * wall.w) * 4;
	if (i < wall.w * wall.h * 4)
	{
		color.x = wall.img_str[i];
		color.y = wall.img_str[i + 1];
		color.z = wall.img_str[i + 2];
	}
	else
	{
		color.x = '0';
		color.y = '0';
		color.z = '0';
	}
	return (color);
}

t_vect_d3			put_wall_texture_e(int x, int y,
		t_wolf3d_data *data, double distance)
{
	int		x_tex;
	int		y_tex;
	double	x_wall;

	y_tex = ((double)y - (WIN_HIGH - distance) / 2 + data->cam_pos->head_rot)
		/ distance * data->walls[1].h;
	x_wall = (first_wall_met(data->map,
				ft_vd2_new(data->cam_pos->x, data->cam_pos->y),
				mod_2pi(data->cam_pos->rotation - ((WIN_LENGTH / 2 - x) * M_PI)
					/ (3 * WIN_LENGTH)))).x;
	x_tex = (int)((x_wall - floor(x_wall)) * data->walls[1].w);
	return (texture_color_e(x_tex, y_tex, data->walls[1]));
}

static t_vect_d3	texture_color_w(int x, int y, t_texture wall)
{
	int			i;
	t_vect_d3	color;

	i = (wall.w - x + y * wall.w) * 4;
	if (i < wall.w * wall.h * 4)
	{
		color.x = wall.img_str[i];
		color.y = wall.img_str[i + 1];
		color.z = wall.img_str[i + 2];
	}
	else
	{
		color.x = '0';
		color.y = '0';
		color.z = '0';
	}
	return (color);
}

t_vect_d3			put_wall_texture_w(int x, int y,
		t_wolf3d_data *data, double distance)
{
	int		x_tex;
	int		y_tex;
	double	x_wall;

	y_tex = ((double)y - (WIN_HIGH - distance) / 2 + data->cam_pos->head_rot)
		/ distance * data->walls[3].h;
	x_wall = (first_wall_met(data->map,
				ft_vd2_new(data->cam_pos->x, data->cam_pos->y),
				mod_2pi(data->cam_pos->rotation - ((WIN_LENGTH / 2 - x) * M_PI)
					/ (3 * WIN_LENGTH)))).x;
	x_tex = (int)((x_wall - floor(x_wall)) * data->walls[3].w);
	return (texture_color_w(x_tex, y_tex, data->walls[3]));
}
