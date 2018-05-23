/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_actual_view.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:09:19 by bspindle          #+#    #+#             */
/*   Updated: 2018/02/27 16:33:04 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				draw_actual_view(t_wolf3d_data *wolf3d)
{
	pthread_t		thread_tab[THREAD_NBR];
	t_wolf_thread	*data_tab[THREAD_NBR];
	int				i;

	i = 0;
	while (i < THREAD_NBR)
	{
		data_tab[i] = (t_wolf_thread*)malloc(sizeof(t_wolf_thread));
		if (!data_tab[i])
			exit_prog(wolf3d);
		data_tab[i]->thread_nbr = i;
		data_tab[i]->wolf3d = wolf3d;
		pthread_create(&thread_tab[i], NULL, thread, data_tab[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_NBR)
	{
		pthread_join(thread_tab[i], NULL);
		free(data_tab[i]);
		i++;
	}
}
