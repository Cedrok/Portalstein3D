/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:17:12 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/16 09:45:33 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	unsigned char	x;
	size_t			i;

	x = (unsigned char)c;
	tmp_dst = (unsigned char*)dst;
	tmp_src = (unsigned char*)src;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n && tmp_src[i] != x)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	if (tmp_src[i] == x && i < n)
	{
		tmp_dst[i] = tmp_src[i];
		dst = (void*)(dst + i + 1);
		return (dst);
	}
	return (NULL);
}
