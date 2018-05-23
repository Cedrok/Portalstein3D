/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:22:04 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/18 13:54:46 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*new;
	t_list	*current_new;

	if (lst == NULL || !(new = ft_lstnew(NULL, 0)))
		return (NULL);
	current_new = new;
	current = lst;
	while (current)
	{
		current_new->next = (*f)(current);
		current = current->next;
		current_new = current_new->next;
	}
	current_new = new->next;
	free(new);
	return (current_new);
}
