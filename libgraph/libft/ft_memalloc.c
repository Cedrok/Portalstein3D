/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:10:02 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/10 14:23:19 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void				*data;
	char				*filler;
	unsigned int		i;

	if (!(data = malloc(size)))
		return (NULL);
	filler = data;
	i = 0;
	while (i < size)
	{
		filler[i] = 0;
		i++;
	}
	return (data);
}
