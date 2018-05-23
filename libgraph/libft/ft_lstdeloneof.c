/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deloneof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:08:55 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/29 15:20:20 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdeloneof(t_list *to_del, t_list **lst)
{
	t_list	*current;
	t_list	*previous;

	if (!lst || !(*lst))
		return ;
	previous = *lst;
	if (previous == to_del)
	{
		*lst = (*lst)->next;
		if (previous->content)
			free(previous->content);
		free(previous);
		return ;
	}
	while (previous->next && previous->next != to_del)
		previous = previous->next;
	if (previous->next == to_del)
	{
		current = previous->next;
		previous->next = current->next;
		if (current->content)
			free(current->content);
		free(current);
	}
}
