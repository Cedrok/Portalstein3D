/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:21:43 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/16 09:49:57 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	i;
	int x;
	int	n;

	n = (int)len;
	i = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0' && i < n)
	{
		x = 0;
		while (str[i] != to_find[x] && str[i] != '\0' && i < n)
			i++;
		while (str[i + x] == to_find[x] && str[i + x] != '\0' && i + x < n)
			x++;
		if (to_find[x] == '\0')
			return ((char*)(str + i));
		if (str[i] != '\0')
			i++;
	}
	return (NULL);
}
