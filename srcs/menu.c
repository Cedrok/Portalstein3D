/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvautrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:39:25 by cvautrai          #+#    #+#             */
/*   Updated: 2018/03/01 17:25:56 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	text_main_menu(t_wolf3d_data *wolf)
{
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->menu.b_resume.img,
			WIN_LENGTH / 2 - wolf->menu.b_resume.w / 2,
			WIN_HIGH - 400 - wolf->menu.b_resume.h);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->menu.b_restart.img,
			WIN_LENGTH / 2 - wolf->menu.b_restart.w / 2,
			WIN_HIGH - 300 - wolf->menu.b_restart.h);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->menu.b_map.img,
			WIN_LENGTH / 2 - wolf->menu.b_map.w / 2,
			WIN_HIGH - 200 - wolf->menu.b_map.h);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->menu.b_exit.img,
			WIN_LENGTH / 2 - wolf->menu.b_exit.w / 2,
			WIN_HIGH - 100 - wolf->menu.b_exit.h);
}

static void	text_map_menu(t_wolf3d_data *wolf)
{
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->menu.b_map_a.img,
			WIN_LENGTH / 2 - wolf->menu.b_map_a.w / 2,
			WIN_HIGH - 400 - wolf->menu.b_map_a.h);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->menu.b_map_b.img,
			WIN_LENGTH / 2 - wolf->menu.b_map_b.w / 2,
			WIN_HIGH - 300 - wolf->menu.b_map_b.h);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->menu.b_map_c.img,
			WIN_LENGTH / 2 - wolf->menu.b_map_c.w / 2,
			WIN_HIGH - 200 - wolf->menu.b_map_c.h);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->menu.b_return.img,
			WIN_LENGTH / 2 - wolf->menu.b_return.w / 2,
			WIN_HIGH - 100 - wolf->menu.b_return.h);
}

static void	place_selec(t_wolf3d_data *wolf, t_texture button, int offset)
{
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->menu.selec_l.img,
			WIN_LENGTH / 2 - (button.w + wolf->menu.selec_l.w) / 2,
			WIN_HIGH - offset - (button.h + wolf->menu.selec_l.h) / 2);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->menu.selec_r.img,
			WIN_LENGTH / 2 + (button.w - wolf->menu.selec_l.w) / 2,
			WIN_HIGH - offset - (button.h + wolf->menu.selec_l.h) / 2);
}

static void	display_selec(t_wolf3d_data *wolf)
{
	if (wolf->menu.display == 1 && wolf->menu.button == 1)
		place_selec(wolf, wolf->menu.b_resume, 400);
	if (wolf->menu.display == 1 && wolf->menu.button == 2)
		place_selec(wolf, wolf->menu.b_restart, 300);
	if (wolf->menu.display == 1 && wolf->menu.button == 3)
		place_selec(wolf, wolf->menu.b_map, 200);
	if (wolf->menu.display == 1 && wolf->menu.button == 4)
		place_selec(wolf, wolf->menu.b_exit, 100);
	if (wolf->menu.display == 2 && wolf->menu.button == 1)
		place_selec(wolf, wolf->menu.b_map_a, 400);
	if (wolf->menu.display == 2 && wolf->menu.button == 2)
		place_selec(wolf, wolf->menu.b_map_b, 300);
	if (wolf->menu.display == 2 && wolf->menu.button == 3)
		place_selec(wolf, wolf->menu.b_map_c, 200);
	if (wolf->menu.display == 2 && wolf->menu.button == 4)
		place_selec(wolf, wolf->menu.b_return, 100);
}

void		menu(t_wolf3d_data *wolf)
{
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->menu.bg.img, 0, 0);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->menu.title.img, WIN_LENGTH / 2 - wolf->menu.title.w / 2, 0);
	display_selec(wolf);
	if (wolf->menu.display == 1)
		text_main_menu(wolf);
	if (wolf->menu.display == 2)
		text_map_menu(wolf);
}
