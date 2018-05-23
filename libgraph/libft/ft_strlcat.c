/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:40:59 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/16 10:04:56 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = ((size_t)ft_strlen(dst));
	if (size > i)
	{
		dst = ft_strncat(dst, src, size - ft_strlen(dst) - 1);
		return (ft_strlen(src) + i);
	}
	return (ft_strlen(src) + size);
}
