/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:48:48 by bspindle          #+#    #+#             */
/*   Updated: 2018/01/17 14:29:18 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_data	*ft_new_data(int size_x, int size_y, char *window_name)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, size_x, size_y, window_name);
	data->image = mlx_new_image(data->mlx, size_x, size_y);
	data->image_str = mlx_get_data_addr(data->image, &data->bpp,
			&data->size_line, &data->endian);
	data->size_line /= 4;
	return (data);
}
