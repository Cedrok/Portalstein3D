/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_chartab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:37:14 by bspindle          #+#    #+#             */
/*   Updated: 2018/03/01 13:21:22 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_chartab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
		while (i >= 0)
		{
			free(tab[i]);
			tab[i] = NULL;
			i--;
		}
		free(tab);
		tab = NULL;
	}
}
