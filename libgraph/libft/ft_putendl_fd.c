/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:50:36 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/10 14:30:12 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl_fd(char const *str, int fd)
{
	if (str == NULL)
		return ;
	while (*str != '\0')
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
	ft_putchar_fd('\n', fd);
}
