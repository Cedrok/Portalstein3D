/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:55:22 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/16 09:51:49 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	newstr = ft_strnew(len);
	if (s == NULL)
		return (NULL);
	if (newstr == NULL)
		return (newstr);
	while (i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	return (newstr);
}
