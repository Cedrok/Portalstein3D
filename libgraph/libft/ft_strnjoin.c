/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:29:16 by bspindle          #+#    #+#             */
/*   Updated: 2018/01/18 09:56:46 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char const *s1, char const *s2, int n)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	newstr = ft_strncat(newstr, s1, n);
	newstr = ft_strncat(newstr, s2, n);
	return (newstr);
}
