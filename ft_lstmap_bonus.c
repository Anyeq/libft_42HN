/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:57:08 by asando            #+#    #+#             */
/*   Updated: 2025/03/17 16:21:11 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> apply a function to a node and put it on the result
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 3)
 * ==> 1.t_list * 2. function 3.function
 * WORK
 * ==> traverse every node and apply function from parameter 1 to every node
 * ==> the new node will have a new address
 * ==> clear the old link list
 * RETURN
 * ==> address new link list
 * REFERENCE
 * ==> link list
 * ==> high order function
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*result;

	result = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_node);
		lst = lst->next;
	}
	return (result);
}
