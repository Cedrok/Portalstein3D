/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_key_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:15:42 by bspindle          #+#    #+#             */
/*   Updated: 2018/03/05 14:31:05 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			exit_prog(t_wolf3d_data *wolf)
{
	free_wolf3d_data(wolf);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	looking_dir(int keycode, t_wolf3d_data *param)
{
	if (keycode == K_PAGE_DOWN)
	{
		if (param->cam_pos->head_rot < 400)
			param->cam_pos->head_rot += 20;
	}
	if (keycode == K_PAGE_UP)
	{
		if (param->cam_pos->head_rot > -400)
			param->cam_pos->head_rot -= 20;
	}
	if (keycode == K_ARROW_RIGHT || keycode == K_E)
		param->cam_pos->rotation += M_PI / 24;
	if (keycode == K_ARROW_LEFT || keycode == K_Q)
		param->cam_pos->rotation -= M_PI / 24;
	return (1);
}

static int	hud_display(int keycode, t_wolf3d_data *param)
{
	if (keycode == K_L_SH || keycode == K_R_SH)
	{
		if (param->sprint == 1)
			param->sprint = 3;
		else
			param->sprint = 1;
	}
	if (keycode == K_TAB || keycode == K_M)
	{
		if (!param->display_map)
			param->display_map = 1;
		else
			param->display_map = 0;
	}
	return (1);
}

static void	menu_display(t_wolf3d_data *wolf)
{
	if (!wolf->menu.display)
	{
		wolf->menu.display = 1;
		wolf->menu.button = 1;
	}
}

int			wolf3d_key_hook(int keycode, void *wolf3d_data)
{
	t_wolf3d_data	*param;

	param = wolf3d_data;
	if (keycode == K_ESC)
		exit_prog(param);
	if (keycode == K_DEL)
		menu_display(param);
	if (param->menu.display)
		menu_key_hook(keycode, param);
	else
	{
		hud_display(keycode, param);
		looking_dir(keycode, param);
		if (keycode == K_A)
			move_left(param);
		if (keycode == K_D)
			move_right(param);
		if (keycode == K_ARROW_UP || keycode == K_W)
			move_forward(param);
		if (keycode == K_ARROW_DOWN || keycode == K_S)
			move_backward(param);
	}
	return (1);
}
