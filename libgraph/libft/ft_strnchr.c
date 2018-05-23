/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:04:55 by bspindle          #+#    #+#             */
/*   Updated: 2017/12/11 16:08:35 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, int n)
{
	int		i;
	char	x;

	i = 0;
	x = (char)c;
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char*)(s + ft_strlen(s)));
	while (s[i] != '\0' && i < n)
	{
		if (s[i] == x)
			return ((char*)(s + i));
		i++;
	}
	return (NULL);
}
