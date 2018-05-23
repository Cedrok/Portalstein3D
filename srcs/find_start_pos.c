/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_start_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvautrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:40:06 by cvautrai          #+#    #+#             */
/*   Updated: 2018/03/06 14:47:49 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_spot_pos			*find_start_pos(char **map)
{
	t_spot_pos	*spot;
	int			i;
	int			j;

	if (!(spot = (t_spot_pos*)malloc(sizeof(t_spot_pos))))
		return (NULL);
	spot->rotation = M_PI / 6;
	spot->head_rot = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0')
			{
				spot->x = i + 0.5;
				spot->y = j + 0.5;
				return (spot);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
