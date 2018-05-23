/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:20:08 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/16 12:28:55 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstcpy(t_list *lst)
{
	t_list	*new;
	t_list	*current;
	t_list	*current_new;

	if (!lst)
		return (NULL);
	new = ft_lstnew(lst->content, lst->content_size);
	current = lst->next;
	current_new = new;
	while (current)
	{
		current_new->next = ft_lstnew(current->content, current->content_size);
		current = current->next;
		current_new = current_new->next;
	}
	return (new);
}
