/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:40:22 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/10 14:32:10 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_fd(char const *str, int fd)
{
	if (str == NULL)
		return ;
	while (*str != '\0')
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}
