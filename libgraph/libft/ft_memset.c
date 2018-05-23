/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:15:28 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/11 11:29:10 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	x;
	unsigned char	*a;
	size_t			var;

	x = (unsigned char)c;
	var = 0;
	a = b;
	while (var < len)
	{
		a[var] = x;
		var++;
	}
	return (b);
}
