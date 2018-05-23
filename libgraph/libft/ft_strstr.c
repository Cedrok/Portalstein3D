/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:40:00 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/16 09:51:01 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int x;

	i = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		x = 0;
		while (str[i] != to_find[x] && str[i] != '\0')
			i++;
		while (str[i + x] == to_find[x] && str[i + x] != '\0')
			x++;
		if (to_find[x] == '\0')
			return ((char*)(str + i));
		if (str[i] != '\0')
			i++;
	}
	return (NULL);
}
