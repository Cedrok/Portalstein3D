/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_wall_met.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:50:28 by bspindle          #+#    #+#             */
/*   Updated: 2018/02/23 10:13:00 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** ii for x and y increase
*/

static t_vect_d2	next_wall_ii(t_vect_d2 start, double alpha)
{
	t_vect_d2	next_y;
	t_vect_d2	next_x;

	next_y.y = floor(start.y) + 1;
	next_x.x = floor(start.x) + 1;
	next_y.x = start.x + (next_y.y - start.y) / tan(alpha);
	next_x.y = start.y + (next_x.x - start.x) * tan(alpha);
	if (distance_d2(start, next_y) < distance_d2(start, next_x))
		return (next_y);
	else
		return (next_x);
}

/*
**d for x decrease, i for y increase
*/

static t_vect_d2	next_wall_di(t_vect_d2 start, double alpha)
{
	t_vect_d2	next_y;
	t_vect_d2	next_x;

	next_y.y = floor(start.y) + 1;
	if (start.x != floor(start.x))
		next_x.x = floor(start.x);
	else
		next_x.x = start.x - 1;
	next_y.x = start.x - (next_y.y - start.y) * tan(alpha - M_PI / 2);
	next_x.y = start.y + (start.x - next_x.x) / tan(alpha - M_PI / 2);
	if (distance_d2(start, next_y) < distance_d2(start, next_x))
		return (next_y);
	else
		return (next_x);
}

static t_vect_d2	next_wall_dd(t_vect_d2 start, double alpha)
{
	t_vect_d2	next_y;
	t_vect_d2	next_x;

	if (start.y != floor(start.y))
		next_y.y = floor(start.y);
	else
		next_y.y = start.y - 1;
	if (start.x != floor(start.x))
		next_x.x = floor(start.x);
	else
		next_x.x = start.x - 1;
	next_y.x = start.x - (start.y - next_y.y) / tan(alpha - M_PI);
	next_x.y = start.y - (start.x - next_x.x) * tan(alpha - M_PI);
	if (distance_d2(start, next_y) < distance_d2(start, next_x))
		return (next_y);
	else
		return (next_x);
}

static t_vect_d2	next_wall_id(t_vect_d2 start, double alpha)
{
	t_vect_d2	next_y;
	t_vect_d2	next_x;

	if (start.y != floor(start.y))
		next_y.y = floor(start.y);
	else
		next_y.y = start.y - 1;
	next_x.x = floor(start.x) + 1;
	next_y.x = start.x + (-next_y.y + start.y) * tan(alpha - 3 * M_PI / 2);
	next_x.y = start.y - (next_x.x - start.x) * tan(2 * M_PI - alpha);
	if (distance_d2(start, next_y) < distance_d2(start, next_x))
		return (next_y);
	else
		return (next_x);
}

t_vect_d2			first_wall_met(char **map, t_vect_d2 start, double alpha)
{
	if (!wall_angle_checker(map, start, alpha))
		return (start);
	if (alpha == 0)
		return (first_wall_met(map, next_wall_right(start), alpha));
	else if (alpha < M_PI / 2)
		return (first_wall_met(map, next_wall_ii(start, alpha), alpha));
	else if (alpha == M_PI / 2)
		return (first_wall_met(map, next_wall_up(start), alpha));
	else if (alpha < M_PI)
		return (first_wall_met(map, next_wall_di(start, alpha), alpha));
	else if (alpha == M_PI)
		return (first_wall_met(map, next_wall_left(start), alpha));
	else if (alpha < 3 * M_PI / 2)
		return (first_wall_met(map, next_wall_dd(start, alpha), alpha));
	else if (alpha == 3 * M_PI / 2)
		return (first_wall_met(map, next_wall_down(start), alpha));
	else
		return (first_wall_met(map, next_wall_id(start, alpha), alpha));
}
