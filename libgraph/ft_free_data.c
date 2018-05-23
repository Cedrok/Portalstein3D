/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:07:35 by bspindle          #+#    #+#             */
/*   Updated: 2018/02/06 16:31:01 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_free_data(t_data **data)
{
	if (*data)
	{
		mlx_destroy_image((*data)->mlx, (*data)->image);
		mlx_destroy_window((*data)->mlx, (*data)->window);
		free((*data)->mlx);
		free(*data);
		*data = NULL;
	}
}
