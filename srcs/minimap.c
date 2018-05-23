/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvautrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:16:15 by cvautrai          #+#    #+#             */
/*   Updated: 2018/04/11 09:17:05 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	selec_square(t_wolf3d_data *wolf, int i, int j, t_vect_d2 pos)
{
	if (wolf->cam_pos->x + j >= 0 && wolf->cam_pos->x + j <= wolf->map_h
			&& wolf->cam_pos->y + i >= 0 && wolf->cam_pos->y + i <= wolf->map_w)
	{
		if (wolf->map[(int)wolf->cam_pos->x + j]
				[(int)wolf->cam_pos->y + i] == '1')
		{
			alpha_square(wolf->minimap.img_str, pos,
					ft_vd4_new(250, 250, 250, 142));
		}
		if (wolf->map[(int)wolf->cam_pos->x + j]
				[(int)wolf->cam_pos->y + i] == '0')
		{
			alpha_square(wolf->minimap.img_str, pos,
					ft_vd4_new(0, 144, 249, 142));
		}
	}
	else
		alpha_square(wolf->minimap.img_str, pos, ft_vd4_new(0, 0, 0, 255));
}

/*
**	For vertical flip: reverse the incrementation of i
**	For horizontal flip: reverse the incrementation of j
*/

static void	gen_minimap(t_wolf3d_data *wolf)
{
	t_vect_d2	pos;
	int			i;
	int			j;

	pos.x = 5;
	i = 7;
	while (i > -8)
	{
		pos.y = 5;
		j = -7;
		while (j < 8)
		{
			selec_square(wolf, i, j, pos);
			j++;
			pos.y += 10;
		}
		i--;
		pos.x += 10;
	}
	pos.x = 75;
	pos.y = 75;
	draw_circle(wolf->minimap.img_str, pos, ft_vd3_new(236, 189, 62));
}

void		minimap(t_wolf3d_data *wolf)
{
	wolf->minimap.img = mlx_new_image(wolf->data->mlx, 150, 150);
	wolf->minimap.img_str = mlx_get_data_addr(wolf->minimap.img,
			&wolf->minimap.bpp, &wolf->minimap.size_line,
			&wolf->minimap.endian);
	wolf->minimap.size_line /= 4;
	gen_minimap(wolf);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->window,
			wolf->minimap.img, 15, 15);
	mlx_destroy_image(wolf->data->mlx, wolf->minimap.img);
}
