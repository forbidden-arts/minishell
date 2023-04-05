/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:46:15 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/04/05 15:13:41 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "str.h"

void	str_free(t_str *self)
{
	if (self)
	{
		if (self->buffer)
			free(self->buffer);
		*self = (t_str){0};
	}
}

BOOL	str_reserve(t_str *self, size_t additional_capacity)
{
	size_t	new_capacity;
	char	*buffer;

	new_capacity = self->capacity + additional_capacity;
	buffer = malloc(sizeof(char) * new_capacity);
	if (!buffer)
		return (FALSE);
	self->capacity = new_capacity;
	ft_memcpy(buffer, self->buffer, self->length);
	free(self->buffer);
	self->buffer = buffer;
	return (TRUE);
}

BOOL	str_grow(t_str *self)
{
	return (str_reserve(self, self->capacity));
}
