/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:41:52 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/16 09:44:33 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r');
}

static int	ft_nbrlen(const char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static int	ft_greatertest(int sign, const char *str)
{
	if (ft_nbrlen(str) > 19 || (ft_nbrlen(str) == 19 &&
				ft_strcmp(str, "9223372036854775807") > 0))
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int i;
	int nbr;
	int sign;

	nbr = 0;
	i = 0;
	sign = 1;
	while (ft_isblank(str[i]) && str[i])
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (ft_greatertest(sign, str + i) != 1)
		return (ft_greatertest(sign, str + i));
	while (ft_isdigit((int)str[i]))
	{
		nbr = 10 * nbr + sign * (str[i] - 48);
		i++;
	}
	return (nbr);
}
