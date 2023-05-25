/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:47:10 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/10/28 17:55:27 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Deletes and frees the given node and every successor of that node, using
**	the function ’del’ and free(3). Finally, the pointer to the list must be
**	set to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*head;

	if (!lst || !del || !*lst)
		return ;
	head = *lst;
	next = head->next;
	while (next)
	{
		next = head->next;
		ft_lstdelone(head, del);
		head = next;
	}
	ft_lstdelone(head, del);
	*lst = NULL;
}
