/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:09:48 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/11 15:31:38 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
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
	newstr = ft_strcat(newstr, s1);
	newstr = ft_strcat(newstr, s2);
	return (newstr);
}
