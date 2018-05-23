/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 11:50:01 by bspindle          #+#    #+#             */
/*   Updated: 2018/02/27 17:02:39 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_vect_d3	color_choice(int x, int y, t_wolf3d_data *wolf3d, double d)
{
	double		angle;
	t_vect_d2	point;

	angle = wolf3d->cam_pos->rotation
		- ((WIN_LENGTH / 2 - x) * M_PI) / (3 * WIN_LENGTH);
	angle = mod_2pi(angle);
	point = first_wall_met(wolf3d->map, ft_vd2_new(wolf3d->cam_pos->x,
				wolf3d->cam_pos->y), angle);
	if (point.x == floor(point.x) && point.y != floor(point.y))
	{
		if (angle < M_PI / 2 || angle > 3 * M_PI / 2)
			return (put_wall_texture_s(x, y, wolf3d, d));
		return (put_wall_texture_n(x, y, wolf3d, d));
	}
	if (angle < M_PI)
		return (put_wall_texture_w(x, y, wolf3d, d));
	return (put_wall_texture_e(x, y, wolf3d, d));
}

static void			select_pixel_and_color(int x, int y, double distance,
		t_wolf3d_data *wolf3d)
{
	if (y < (WIN_HIGH - distance) / 2 - wolf3d->cam_pos->head_rot)
		ft_fill_pixel(wolf3d->data->image_str, wolf3d->data->size_line,
				ft_vd2_new(x, y), ft_vd3_new(50, 50, 50));
	else if (y < (WIN_HIGH + distance) / 2 - wolf3d->cam_pos->head_rot)
		ft_fill_pixel(wolf3d->data->image_str, wolf3d->data->size_line,
				ft_vd2_new(x, y), color_choice(x, y, wolf3d, distance));
	else
		ft_fill_pixel(wolf3d->data->image_str, wolf3d->data->size_line,
				ft_vd2_new(x, y), ft_vd3_new(255, 255, 255));
}

void				*thread(void *v)
{
	double			distance;
	int				x;
	int				y;
	t_wolf_thread	*th;
	t_wolf3d_data	*wolf3d;

	th = v;
	wolf3d = th->wolf3d;
	x = th->thread_nbr * WIN_LENGTH / THREAD_NBR;
	while (x < WIN_LENGTH * (th->thread_nbr + 1) / THREAD_NBR)
	{
		distance = WIN_HIGH / (find_distance(wolf3d->map, *wolf3d->cam_pos, x));
		y = 0;
		while (y < WIN_HIGH)
		{
			select_pixel_and_color(x, y, distance, wolf3d);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}
