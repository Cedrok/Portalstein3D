/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:00:22 by bspindle          #+#    #+#             */
/*   Updated: 2017/12/11 11:13:27 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new_lst;
	void	*new_content;

	if (!(new_lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_lst->next = NULL;
	if (content == NULL)
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
		return (new_lst);
	}
	if (!(new_content = malloc(content_size)))
		return (NULL);
	if (content)
		ft_memmove(new_content, content, content_size);
	else
		new_content = NULL;
	new_lst->content = new_content;
	new_lst->content_size = content_size;
	return (new_lst);
}
