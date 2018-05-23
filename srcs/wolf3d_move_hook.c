/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_move_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:10:40 by bspindle          #+#    #+#             */
/*   Updated: 2018/03/08 10:09:07 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	wolf3d_move_hook(int x, int y, void *wolf3d)
{
	t_wolf3d_data	*param;

	param = wolf3d;
	if (param->menu.display == 0)
	{
		param->cam_pos->rotation = (double)x * M_PI * 2 / WIN_LENGTH - M_PI;
		param->cam_pos->head_rot = y * 800 / WIN_HIGH - 400;
	}
	else if (param->menu.display == 1)
		switch_main_button(x, y, param);
	else if (param->menu.display == 2)
		switch_map_button(x, y, param);
	return (1);
}
