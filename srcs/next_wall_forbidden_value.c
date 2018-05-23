/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_wall_forbidden_value.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:40:41 by bspindle          #+#    #+#             */
/*   Updated: 2018/02/23 10:14:17 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vect_d2	next_wall_right(t_vect_d2 start)
{
	t_vect_d2	next;

	next.y = start.y;
	next.x = floor(start.x) + 1;
	return (next);
}

t_vect_d2	next_wall_left(t_vect_d2 start)
{
	t_vect_d2	next;

	next.y = start.y;
	if (start.x == floor(start.x))
		next.x = start.x - 1;
	else
		next.x = floor(start.x);
	return (next);
}

t_vect_d2	next_wall_up(t_vect_d2 start)
{
	t_vect_d2	next;

	next.x = start.x;
	next.y = floor(start.y) + 1;
	return (next);
}

t_vect_d2	next_wall_down(t_vect_d2 start)
{
	t_vect_d2	next;

	next.x = start.x;
	if (start.y == floor(start.y))
		next.y = start.y - 1;
	else
		next.y = floor(start.y);
	return (next);
}
