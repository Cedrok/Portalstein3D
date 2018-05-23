/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:02:31 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/10 14:31:31 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int		sign;
	char	str[15];
	int		i;

	i = 0;
	sign = 1;
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		sign = -1;
		write(fd, "-", 1);
	}
	while (n != 0)
	{
		i++;
		str[i] = (n % (sign * 10)) * sign + 48;
		n = n / 10;
	}
	while (i > 0)
	{
		ft_putchar_fd(str[i], fd);
		i--;
	}
}
