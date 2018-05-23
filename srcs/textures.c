/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvautrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:20:02 by cvautrai          #+#    #+#             */
/*   Updated: 2018/03/08 16:22:54 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_texture	get_texture(t_wolf3d_data *wolf3d, char *path)
{
	t_texture tx;

	if (!(tx.img = mlx_xpm_file_to_image(wolf3d->data->mlx, path,
					&tx.w, &tx.h)))
	{
		ft_putstr("Texture loading failed : ");
		ft_putendl(path);
		exit_prog(wolf3d);
	}
	if (!(tx.img_str = mlx_get_data_addr(tx.img, &tx.bpp, &tx.size_line,
					&tx.endian)))
		exit_prog(wolf3d);
	return (tx);
}

t_texture	*load_walls(t_wolf3d_data *wolf3d)
{
	t_texture	*walls;

	if (!(walls = (t_texture*)malloc(sizeof(t_texture) * 4)))
		return (NULL);
	walls[0] = get_texture(wolf3d, "textures/wall1_n.xpm");
	walls[1] = get_texture(wolf3d, "textures/wall1_e.xpm");
	walls[2] = get_texture(wolf3d, "textures/wall1_s.xpm");
	walls[3] = get_texture(wolf3d, "textures/wall1_w.xpm");
	return (walls);
}

void		load_all_textures(t_wolf3d_data *wolf3d)
{
	if (!(wolf3d->walls = load_walls(wolf3d)))
		exit_prog(wolf3d);
	wolf3d->floor = get_texture(wolf3d, "textures/floor.xpm");
	wolf3d->roof = get_texture(wolf3d, "textures/roof.xpm");
	wolf3d->gun = get_texture(wolf3d, "textures/n_portal_gun.xpm");
	wolf3d->cursor = get_texture(wolf3d, "textures/cursor.xpm");
	wolf3d->p_sprint = get_texture(wolf3d, "textures/sprint.xpm");
	wolf3d->menu.bg = get_texture(wolf3d, "textures/background.xpm");
	wolf3d->menu.title = get_texture(wolf3d, "textures/title.xpm");
	wolf3d->menu.b_resume = get_texture(wolf3d, "textures/b_resume.xpm");
	wolf3d->menu.b_restart = get_texture(wolf3d, "textures/b_restart.xpm");
	wolf3d->menu.b_map = get_texture(wolf3d, "textures/b_map.xpm");
	wolf3d->menu.b_exit = get_texture(wolf3d, "textures/b_exit.xpm");
	wolf3d->menu.b_map_a = get_texture(wolf3d, "textures/b_map_a.xpm");
	wolf3d->menu.b_map_b = get_texture(wolf3d, "textures/b_map_b.xpm");
	wolf3d->menu.b_map_c = get_texture(wolf3d, "textures/b_map_c.xpm");
	wolf3d->menu.b_return = get_texture(wolf3d, "textures/b_return.xpm");
	wolf3d->menu.selec_l = get_texture(wolf3d, "textures/selec_l.xpm");
	wolf3d->menu.selec_r = get_texture(wolf3d, "textures/selec_r.xpm");
}
