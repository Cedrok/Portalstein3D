/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:32:17 by bspindle          #+#    #+#             */
/*   Updated: 2017/12/14 10:42:43 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list **lst)
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		ft_putstr((char*)(current->content));
		ft_putchar('\n');
		ft_putnbr(current->content_size);
		ft_putchar('\n');
		current = current->next;
	}
}
