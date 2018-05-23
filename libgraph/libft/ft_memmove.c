/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:11:11 by bspindle          #+#    #+#             */
/*   Updated: 2017/12/14 10:42:27 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memmove(void *dst, const void *src, size_t len)
{
	char	*strsrc;
	char	*strdst;
	size_t	i;

	strsrc = (char*)src;
	strdst = (char*)dst;
	if (strsrc < strdst)
	{
		len--;
		while (len > 0)
		{
			strdst[len] = strsrc[len];
			len--;
		}
	}
	else
	{
		i = 0;
		while (len - i > 0)
		{
			strdst[i] = strsrc[i];
			i++;
		}
	}
}
