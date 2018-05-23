/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 10:46:03 by bspindle          #+#    #+#             */
/*   Updated: 2018/02/28 09:06:21 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		free_wolf3d_data(t_wolf3d_data *wolf3d)
{
	if (wolf3d->map)
		ft_del_chartab(wolf3d->map);
	if (wolf3d->cam_pos)
		free(wolf3d->cam_pos);
	if (wolf3d->data)
	{
		mlx_destroy_window(wolf3d->data->mlx, wolf3d->data->window);
		free(wolf3d->data->mlx);
		free(wolf3d->data);
		wolf3d->data = NULL;
	}
	wolf3d = NULL;
}
