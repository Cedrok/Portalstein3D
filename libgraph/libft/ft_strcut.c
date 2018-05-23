/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:15:39 by bspindle          #+#    #+#             */
/*   Updated: 2017/12/01 09:07:44 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, int n)
{
	if (str)
	{
		if ((size_t)n < ft_strlen(str))
			return (str + n);
		else
			free(str);
	}
	return (NULL);
}
