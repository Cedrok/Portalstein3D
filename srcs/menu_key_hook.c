/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvautrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 08:51:38 by cvautrai          #+#    #+#             */
/*   Updated: 2018/03/08 09:40:08 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		event_main_menu(t_wolf3d_data *wolf)
{
	if (wolf->menu.button == 1)
		wolf->menu.display = 0;
	if (wolf->menu.button == 2)
	{
		free(wolf->cam_pos);
		wolf->cam_pos = find_start_pos(wolf->map);
		wolf->sprint = 1;
		wolf->menu.display = 0;
		wolf->display_map = 0;
	}
	if (wolf->menu.button == 3)
	{
		wolf->menu.display = 2;
		wolf->menu.button = 1;
	}
	if (wolf->menu.button == 4)
		exit_prog(wolf);
}

static void	new_map(t_wolf3d_data *wolf, char *arg)
{
	char *line;

	line = NULL;
	ft_del_chartab(wolf->map);
	free(wolf->cam_pos);
	if (!(wolf->map = get_map(arg, line, wolf)))
	{
		ft_putendl("Map generation failed");
		exit_prog(wolf);
	}
	if (!(wolf->cam_pos = find_start_pos(wolf->map)))
	{
		ft_putendl("No starting position :(");
		exit_prog(wolf);
	}
	wolf->sprint = 1;
	wolf->display_map = 0;
	wolf->menu.display = 0;
	ft_strdel(&line);
}

void		event_map_menu(t_wolf3d_data *wolf)
{
	char	*line;

	line = NULL;
	if (wolf->menu.button == 1)
		new_map(wolf, "map/map01");
	if (wolf->menu.button == 2)
		new_map(wolf, "map/map02");
	if (wolf->menu.button == 3)
		new_map(wolf, "map/map03");
	if (wolf->menu.button == 4)
	{
		wolf->menu.display = 1;
		wolf->menu.button = 1;
	}
	ft_strdel(&line);
}

int			menu_key_hook(int keycode, t_wolf3d_data *wolf)
{
	if (keycode == K_ARROW_DOWN)
	{
		if (wolf->menu.button < 4)
			wolf->menu.button++;
	}
	if (keycode == K_ARROW_UP)
	{
		if (wolf->menu.button > 1)
			wolf->menu.button--;
	}
	if (keycode == K_RET)
	{
		if (wolf->menu.display == 1)
			event_main_menu(wolf);
		else if (wolf->menu.display == 2)
			event_map_menu(wolf);
	}
	return (1);
}
