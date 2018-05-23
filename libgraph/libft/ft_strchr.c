/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:20:49 by bspindle          #+#    #+#             */
/*   Updated: 2017/12/11 12:21:50 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	x;

	i = 0;
	x = (char)c;
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char*)(s + ft_strlen(s)));
	while (s[i] != '\0')
	{
		if (s[i] == x)
			return ((char*)(s + i));
		i++;
	}
	return (NULL);
}
