/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:21:35 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/16 09:52:09 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;
	char	*strtrimed;

	start = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[start] == '\t' || s[start] == '\n' || s[start] == ' ')
	{
		if (start == len)
		{
			if (!(strtrimed = ft_strnew(0)))
				return (NULL);
			return (strtrimed);
		}
		start++;
	}
	while (s[len] == '\t' || s[len] == '\n' || s[len] == ' ')
		len--;
	if (!(strtrimed = ft_strsub(s, start, len + 1 - start)))
		return (NULL);
	return (strtrimed);
}
