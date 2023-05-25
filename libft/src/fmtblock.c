/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmtblock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:13:07 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:13:26 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fmtblock.h"

t_fmtblock	*fmtblock_new(char *p, size_t len, BOOL dynamic)
{
	t_fmtblock	*block;

	block = malloc(sizeof(t_fmtblock));
	if (!block)
		return (NULL);
	block->next = NULL;
	block->p = p;
	block->len = len;
	block->dynamic = dynamic;
	return (block);
}

int	fmtblock_write_all(t_fmtblock *list, int fd)
{
	int			len;
	t_fmtblock	*next;
	t_fmtblock	*head;

	len = 0;
	head = list;
	while (head)
	{
		next = head->next;
		write(fd, head->p, head->len);
		len += head->len;
		if (head->dynamic == TRUE)
			free(head->p);
		free(head);
		head = next;
	}
	return (len);
}

void	*fmtblock_free_all(t_fmtblock *head)
{
	t_fmtblock	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
	return (NULL);
}
