/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:33:14 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/16 09:46:07 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	x;
	size_t	i;

	i = 0;
	x = (char)c;
	str = (char*)s;
	while (i < n)
	{
		if (str[i] == x)
		{
			str = str + i;
			return ((void*)str);
		}
		i++;
	}
	return (NULL);
}
