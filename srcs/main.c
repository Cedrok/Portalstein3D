/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:44:38 by bspindle          #+#    #+#             */
/*   Updated: 2018/04/16 16:42:50 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			display_hud(t_wolf3d_data *wolf3d)
{
	mlx_put_image_to_window(wolf3d->data->mlx, wolf3d->data->window,
			wolf3d->gun.img, WIN_LENGTH / 2 + osci_x(5, 0.5) * wolf3d->sprint,
			WIN_HIGH - wolf3d->gun.h + 150 + osci_y(10, 0.5) * wolf3d->sprint);
	mlx_put_image_to_window(wolf3d->data->mlx, wolf3d->data->window,
			wolf3d->cursor.img, WIN_LENGTH / 2 - wolf3d->cursor.w / 2,
			WIN_HIGH / 2 - wolf3d->cursor.h / 2);
	if (wolf3d->sprint != 1)
	{
		mlx_put_image_to_window(wolf3d->data->mlx, wolf3d->data->window,
				wolf3d->p_sprint.img, 0, WIN_HIGH - wolf3d->p_sprint.h);
	}
	if (wolf3d->display_map)
		minimap(wolf3d);
}

static int			update(t_wolf3d_data *wolf3d)
{
	if (wolf3d->menu.display)
		menu(wolf3d);
	else
	{
		wolf3d->data->image = mlx_new_image(wolf3d->data->mlx,
				WIN_LENGTH, WIN_HIGH);
		if (!(wolf3d->data->image_str = mlx_get_data_addr(wolf3d->data->image,
				&wolf3d->data->bpp, &wolf3d->data->size_line,
				&wolf3d->data->endian)))
			exit_prog(wolf3d);
		wolf3d->data->size_line /= 4;
		draw_actual_view(wolf3d);
		mlx_put_image_to_window(wolf3d->data->mlx, wolf3d->data->window,
				wolf3d->data->image, 0, 0);
		display_hud(wolf3d);
		mlx_do_sync(wolf3d->data->mlx);
		mlx_destroy_image(wolf3d->data->mlx, wolf3d->data->image);
	}
	return (1);
}

static void			init_values(t_wolf3d_data *wolf)
{
	wolf->sprint = 1;
	wolf->display_map = 0;
	wolf->menu.display = 1;
	wolf->menu.button = 1;
}

static void			start(t_wolf3d_data *wolf3d, char *arg)
{
	char		*line;

	line = NULL;
	if (!(wolf3d->map = get_map(arg, line, wolf3d)))
	{
		ft_putendl("Map generation failed");
		exit_prog(wolf3d);
	}
	if (!(wolf3d->cam_pos = find_start_pos(wolf3d->map)))
	{
		ft_putendl("No starting position :(");
		exit_prog(wolf3d);
	}
	if (!(wolf3d->data = (t_data*)malloc(sizeof(t_data))))
		exit_prog(wolf3d);
	if (!(wolf3d->data->mlx = mlx_init()))
		exit_prog(wolf3d);
	wolf3d->data->window = mlx_new_window(wolf3d->data->mlx, WIN_LENGTH,
			WIN_HIGH, "Portalstein 3D");
	load_all_textures(wolf3d);
	init_values(wolf3d);
	ft_strdel(&line);
}

int					main(int ac, char **av)
{
	t_wolf3d_data	wolf3d;

	if (ac >= 2)
	{
		if (!(ft_strcmp(av[1], "-help")))
		{
			ft_putendl("If no argument is given, launch with default map");
			ft_putstr("If several arguments are given, ");
			ft_putendl("launch with the first of them");
			exit_prog(&wolf3d);
		}
		start(&wolf3d, av[1]);
	}
	else
	{
		ft_putendl(" -> Default map launched");
		start(&wolf3d, "map/map01");
	}
	mlx_hook(wolf3d.data->window, 2, 5, wolf3d_key_hook, &wolf3d);
	mlx_hook(wolf3d.data->window, 6, 0, wolf3d_move_hook, &wolf3d);
	mlx_mouse_hook(wolf3d.data->window, menu_mouse_hook, &wolf3d);
	mlx_hook(wolf3d.data->window, 17, (1L << 17), exit_prog, &wolf3d);
	mlx_loop_hook(wolf3d.data->mlx, update, &wolf3d);
	mlx_loop(wolf3d.data->mlx);
	return (1);
}
