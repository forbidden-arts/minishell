/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:15:12 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/10/29 00:38:10 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (!result)
		return (NULL);
	head = result;
	while (lst->next)
	{
		head->next = ft_lstnew(f(lst->next->content));
		if (!head->next)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		head = head->next;
		lst = lst->next;
	}
	return (result);
}
