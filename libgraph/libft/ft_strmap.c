/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:48:14 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/16 12:34:59 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		i;

	if (s == NULL)
		return (NULL);
	if (!(new_str = ft_strnew((size_t)ft_strlen((char*)s))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_str[i] = (*f)(s[i]);
		i++;
	}
	return (new_str);
}
