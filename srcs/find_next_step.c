/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:53:18 by bspindle          #+#    #+#             */
/*   Updated: 2018/03/05 14:31:03 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	check_hitbox(char **map, double rotation, t_vect_d2 start)
{
	t_vect_d2	a;
	t_vect_d2	b;
	t_vect_d2	c;
	t_vect_d2	d;

	a.x = start.x + 0.025 * (cos(rotation) + cos(rotation - M_PI / 2));
	a.y = start.y + 0.025 * (cos(rotation) + cos(rotation - M_PI / 2));
	b.x = start.x - 0.025 * (cos(rotation) + cos(rotation - M_PI / 2));
	b.y = start.y + 0.025 * (cos(rotation) + cos(rotation - M_PI / 2));
	c.x = start.x - 0.025 * (cos(rotation) + cos(rotation - M_PI / 2));
	c.y = start.y - 0.025 * (cos(rotation) + cos(rotation - M_PI / 2));
	d.x = start.x + 0.025 * (cos(rotation) + cos(rotation - M_PI / 2));
	d.y = start.y - 0.025 * (cos(rotation) + cos(rotation - M_PI / 2));
	return (map[(int)a.x][(int)a.y] != '0'
			&& map[(int)b.x][(int)b.y] != '0'
			&& map[(int)c.x][(int)c.y] != '0'
			&& map[(int)d.x][(int)d.y] != '0');
}

void		move_forward(t_wolf3d_data *data)
{
	t_spot_pos	new_pos;
	t_vect_d2	start;
	t_vect_d2	next;

	new_pos.x = data->cam_pos->x + 0.05 * cos(data->cam_pos->rotation)
		* data->sprint;
	new_pos.y = data->cam_pos->y + 0.05 * sin(data->cam_pos->rotation)
		* data->sprint;
	start = ft_vd2_new(new_pos.x, new_pos.y);
	next.x = start.x + 0.05 * cos(data->cam_pos->rotation) * 4;
	next.y = start.y + 0.05 * sin(data->cam_pos->rotation) * 4;
	if (data->map[(int)new_pos.x][(int)new_pos.y] != '0'
			&& check_hitbox(data->map, data->cam_pos->rotation, start) != 0
				&& check_hitbox(data->map, data->cam_pos->rotation, next) != 0)
	{
		data->cam_pos->x = new_pos.x;
		data->cam_pos->y = new_pos.y;
	}
}

void		move_backward(t_wolf3d_data *data)
{
	t_spot_pos	new_pos;
	t_vect_d2	start;
	t_vect_d2	next;

	new_pos.x = data->cam_pos->x - 0.05 * cos(data->cam_pos->rotation)
		* data->sprint;
	new_pos.y = data->cam_pos->y - 0.05 * sin(data->cam_pos->rotation)
		* data->sprint;
	start = ft_vd2_new(new_pos.x, new_pos.y);
	next.x = start.x - 0.05 * cos(data->cam_pos->rotation) * 4;
	next.y = start.y - 0.05 * sin(data->cam_pos->rotation) * 4;
	if (data->map[(int)new_pos.x][(int)new_pos.y] != '0'
			&& check_hitbox(data->map, data->cam_pos->rotation, start) != 0
				&& check_hitbox(data->map, data->cam_pos->rotation, next) != 0)
	{
		data->cam_pos->x = new_pos.x;
		data->cam_pos->y = new_pos.y;
	}
}

void		move_right(t_wolf3d_data *data)
{
	t_spot_pos	new;
	t_vect_d2	start;
	t_vect_d2	next;

	new.x = data->cam_pos->x - 0.05 * cos(data->cam_pos->rotation - M_PI / 2)
		* data->sprint;
	new.y = data->cam_pos->y - 0.05 * sin(data->cam_pos->rotation - M_PI / 2)
		* data->sprint;
	start = ft_vd2_new(new.x, new.y);
	next.x = start.x - 0.05 * cos(data->cam_pos->rotation - M_PI / 2) * 4;
	next.y = start.y - 0.05 * sin(data->cam_pos->rotation - M_PI / 2) * 4;
	if (data->map[(int)new.x][(int)new.y] != '0'
			&& check_hitbox(data->map, data->cam_pos->rotation, start) != 0
				&& check_hitbox(data->map, data->cam_pos->rotation, next) != 0)
	{
		data->cam_pos->x = new.x;
		data->cam_pos->y = new.y;
	}
}

void		move_left(t_wolf3d_data *data)
{
	t_spot_pos	new;
	t_vect_d2	start;
	t_vect_d2	next;

	new.x = data->cam_pos->x + 0.05 * cos(data->cam_pos->rotation - M_PI / 2)
		* data->sprint;
	new.y = data->cam_pos->y + 0.05 * sin(data->cam_pos->rotation - M_PI / 2)
		* data->sprint;
	start = ft_vd2_new(new.x, new.y);
	next.x = start.x + 0.05 * cos(data->cam_pos->rotation - M_PI / 2) * 4;
	next.y = start.y + 0.05 * sin(data->cam_pos->rotation - M_PI / 2) * 4;
	if (data->map[(int)new.x][(int)new.y] != '0'
			&& check_hitbox(data->map, data->cam_pos->rotation, start) != 0
				&& check_hitbox(data->map, data->cam_pos->rotation, next) != 0)
	{
		data->cam_pos->x = new.x;
		data->cam_pos->y = new.y;
	}
}
