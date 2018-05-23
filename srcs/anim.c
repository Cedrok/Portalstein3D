/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvautrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:05:38 by cvautrai          #+#    #+#             */
/*   Updated: 2018/02/23 15:16:01 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float	osci_x(float max, float step)
{
	static float	n = 0;
	static int		dir = 0;

	if (dir == 0)
	{
		n += step;
		if (n >= max)
			dir = 1;
	}
	if (dir == 1)
	{
		n -= step;
		if (n <= 0)
			dir = 0;
	}
	return (n);
}

float	osci_y(float max, float step)
{
	static float	n = 0;
	static int		dir = 0;

	if (dir == 0)
	{
		n += step;
		if (n >= max)
			dir = 1;
	}
	if (dir == 1)
	{
		n -= step;
		if (n <= 0)
			dir = 0;
	}
	return (n);
}

float	trans(float end, float step)
{
	static float	n = 0;

	if (end > 0)
	{
		if (n < end)
			n += step;
	}
	if (end < 0)
	{
		if (n > end)
			n -= step;
	}
	return (n);
}
