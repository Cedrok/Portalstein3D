/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:56:45 by bspindle          #+#    #+#             */
/*   Updated: 2017/12/01 10:06:24 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelfirst(t_list **lst)
{
	t_list	*save;

	if (*lst)
	{
		save = (*lst);
		*lst = (*lst)->next;
		ft_lstdelone(&save);
	}
}
