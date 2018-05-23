/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_mouse_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvautrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:23:39 by cvautrai          #+#    #+#             */
/*   Updated: 2018/03/08 10:43:28 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		switch_main_button(int x, int y, t_wolf3d_data *wolf)
{
	if (wolf->menu.button != 1 &&
			x >= WIN_LENGTH / 2 - wolf->menu.b_resume.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_resume.w / 2 &&
			y >= WIN_HIGH - 400 - wolf->menu.b_resume.h &&
			y <= WIN_HIGH - 400)
		wolf->menu.button = 1;
	if (wolf->menu.button != 2 &&
			x >= WIN_LENGTH / 2 - wolf->menu.b_restart.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_restart.w / 2 &&
			y >= WIN_HIGH - 300 - wolf->menu.b_restart.h &&
			y <= WIN_HIGH - 300)
		wolf->menu.button = 2;
	if (wolf->menu.button != 3 &&
			x >= WIN_LENGTH / 2 - wolf->menu.b_map.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_map.w / 2 &&
			y >= WIN_HIGH - 200 - wolf->menu.b_map.h &&
			y <= WIN_HIGH - 200)
		wolf->menu.button = 3;
	if (wolf->menu.button != 4 &&
			x >= WIN_LENGTH / 2 - wolf->menu.b_exit.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_exit.w / 2 &&
			y >= WIN_HIGH - 100 - wolf->menu.b_exit.h &&
			y <= WIN_HIGH - 100)
		wolf->menu.button = 4;
}

void		switch_map_button(int x, int y, t_wolf3d_data *wolf)
{
	if (wolf->menu.button != 1 &&
			x >= WIN_LENGTH / 2 - wolf->menu.b_map_a.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_map_a.w / 2 &&
			y >= WIN_HIGH - 400 - wolf->menu.b_map_a.h &&
			y <= WIN_HIGH - 400)
		wolf->menu.button = 1;
	if (wolf->menu.button != 2 &&
			x >= WIN_LENGTH / 2 - wolf->menu.b_map_b.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_map_b.w / 2 &&
			y >= WIN_HIGH - 300 - wolf->menu.b_map_b.h &&
			y <= WIN_HIGH - 300)
		wolf->menu.button = 2;
	if (wolf->menu.button != 3 &&
			x >= WIN_LENGTH / 2 - wolf->menu.b_map_c.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_map_c.w / 2 &&
			y >= WIN_HIGH - 200 - wolf->menu.b_map_c.h &&
			y <= WIN_HIGH - 200)
		wolf->menu.button = 3;
	if (wolf->menu.button != 4 &&
			x >= WIN_LENGTH / 2 - wolf->menu.b_return.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_return.w / 2 &&
			y >= WIN_HIGH - 100 - wolf->menu.b_return.h &&
			y <= WIN_HIGH - 100)
		wolf->menu.button = 4;
}

static int	on_main_button(int x, int y, t_wolf3d_data *wolf)
{
	if (x >= WIN_LENGTH / 2 - wolf->menu.b_resume.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_resume.w / 2 &&
			y >= WIN_HIGH - 400 - wolf->menu.b_resume.h &&
			y <= WIN_HIGH - 400)
		return (1);
	if (x >= WIN_LENGTH / 2 - wolf->menu.b_restart.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_restart.w / 2 &&
			y >= WIN_HIGH - 300 - wolf->menu.b_restart.h &&
			y <= WIN_HIGH - 300)
		return (1);
	if (x >= WIN_LENGTH / 2 - wolf->menu.b_map.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_map.w / 2 &&
			y >= WIN_HIGH - 200 - wolf->menu.b_map.h &&
			y <= WIN_HIGH - 200)
		return (1);
	if (x >= WIN_LENGTH / 2 - wolf->menu.b_exit.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_exit.w / 2 &&
			y >= WIN_HIGH - 100 - wolf->menu.b_exit.h &&
			y <= WIN_HIGH - 100)
		return (1);
	return (0);
}

static int	on_map_button(int x, int y, t_wolf3d_data *wolf)
{
	if (x >= WIN_LENGTH / 2 - wolf->menu.b_map_a.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_map_a.w / 2 &&
			y >= WIN_HIGH - 400 - wolf->menu.b_map_a.h &&
			y <= WIN_HIGH - 400)
		return (1);
	if (x >= WIN_LENGTH / 2 - wolf->menu.b_map_b.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_map_b.w / 2 &&
			y >= WIN_HIGH - 300 - wolf->menu.b_map_b.h &&
			y <= WIN_HIGH - 300)
		return (1);
	if (x >= WIN_LENGTH / 2 - wolf->menu.b_map_c.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_map_c.w / 2 &&
			y >= WIN_HIGH - 200 - wolf->menu.b_map_c.h &&
			y <= WIN_HIGH - 200)
		return (1);
	if (x >= WIN_LENGTH / 2 - wolf->menu.b_return.w / 2 &&
			x <= WIN_LENGTH / 2 + wolf->menu.b_return.w / 2 &&
			y >= WIN_HIGH - 100 - wolf->menu.b_return.h &&
			y <= WIN_HIGH - 100)
		return (1);
	return (0);
}

int			menu_mouse_hook(int button, int x, int y, t_wolf3d_data *wolf)
{
	if (button == C_LEFT)
	{
		if (wolf->menu.display == 1 && on_main_button(x, y, wolf))
			event_main_menu(wolf);
		else if (wolf->menu.display == 2 && on_map_button(x, y, wolf))
			event_map_menu(wolf);
	}
	return (1);
}
