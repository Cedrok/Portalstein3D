/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_angle_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:47:41 by bspindle          #+#    #+#             */
/*   Updated: 2018/02/23 10:20:33 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	function for select the direction of the wall met
*/

int	wall_angle_checker(char **map, t_vect_d2 start, double alpha)
{
	if (alpha <= M_PI / 2)
		return (map[(int)start.x][(int)start.y] != '0');
	if (alpha <= M_PI)
	{
		return (start.x != floor(start.x) ?
				map[(int)start.x][(int)start.y] != '0'
				: map[(int)(start.x - 1)][(int)start.y] != '0');
	}
	if (alpha <= 3 * M_PI / 2)
	{
		if (start.x == floor(start.x))
			return (map[(int)start.x][(int)start.y] != '0'
					&& map[(int)(start.x - 1)][(int)start.y] != '0');
		else if (start.y == floor(start.y))
			return (map[(int)start.x][(int)start.y] != '0'
					&& map[(int)(start.x)][(int)(start.y - 1)] != '0');
		else
			return (map[(int)start.x][(int)start.y] != '0');
	}
	else
		return (start.y == floor(start.y) ?
				map[(int)start.x][(int)(start.y - 1)] != '0'
				: map[(int)start.x][(int)start.y] != '0');
}
