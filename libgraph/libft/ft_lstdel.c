/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:59:45 by bspindle          #+#    #+#             */
/*   Updated: 2017/12/01 09:15:45 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	t_list	*current;

	current = *alst;
	while (*alst)
	{
		current = (*alst)->next;
		ft_lstdelone(alst);
		*alst = current;
	}
}
