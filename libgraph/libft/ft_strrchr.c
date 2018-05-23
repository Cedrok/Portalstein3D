/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:32:56 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/16 09:50:41 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	x;

	if (c == 0)
		return ((char*)(s + ft_strlen(s)));
	i = ft_strlen(s) - 1;
	x = (char)c;
	while (i >= 0)
	{
		if (s[i] == x)
			return ((char*)(s + i));
		i--;
	}
	return (NULL);
}
