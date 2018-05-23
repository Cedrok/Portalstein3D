/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:10:11 by bspindle          #+#    #+#             */
/*   Updated: 2018/02/08 14:11:03 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_unsigned(int n)
{
	int		sign;
	char	*str;
	int		i;

	if (!(str = (char*)malloc(sizeof(char) * 12)))
		return (NULL);
	i = 0;
	if (n == 0)
	{
		str[0] = '0';
		i++;
	}
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	while (n != 0)
	{
		str[i] = (n % (sign * 10)) * sign + 48;
		n = n / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		x;
	char	*tmp;
	char	*str;

	i = 0;
	if (n < 0)
		i = 1;
	if (!(tmp = ft_unsigned(n)))
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + i + 1))))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	x = ft_strlen(tmp) - 1;
	while (x >= 0)
	{
		str[i] = tmp[x];
		i++;
		x--;
	}
	str[i] = '\0';
	ft_strdel(&tmp);
	return (str);
}
