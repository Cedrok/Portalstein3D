/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:33:37 by bspindle          #+#    #+#             */
/*   Updated: 2018/02/23 10:12:32 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static double	distance_spot_wall(t_spot_pos a, t_vect_d2 v)
{
	double	d;

	d = sqrt((a.x - v.x) * (a.x - v.x) + (a.y - v.y) * (a.y - v.y));
	return (d);
}

double			find_distance(char **map, t_spot_pos position, int x)
{
	double			angle;
	double			d;
	t_vect_d2		start;

	angle = position.rotation - ((WIN_LENGTH / 2 - x) * M_PI)
		/ (3 * WIN_LENGTH);
	angle = mod_2pi(angle);
	start = ft_vd2_new(position.x, position.y);
	d = distance_spot_wall(position, first_wall_met(map, start, angle));
	d *= cos(position.rotation - angle);
	return (d);
}
