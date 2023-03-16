/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:49:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/16 14:24:35 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bool.h"
#include "libft.h"
#include "vector.h"

t_vector	*vector_with_capacity(size_t capacity, size_t elem_size)
{
	t_vector	*self;

	self = malloc(sizeof(t_vector));
	if (!self)
		return (NULL);
	self->length = 0;
	self->capacity = capacity;
	self->elem_size = elem_size;
	self->buffer = malloc(sizeof(elem_size) * capacity);
	if (!self->buffer)
	{
		free(self);
		return (NULL);
	}
	return (self);
}

t_vector	*vector_grow(t_vector *self)
{
	char	*buffer;
	size_t	new_capacity;

	if (!self)
		return (NULL);
	new_capacity = self->capacity * 2;
	buffer = malloc(new_capacity * sizeof(self->elem_size));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, self->buffer, self->length);
	free(self->buffer);
	self->buffer = buffer;
	self->capacity = new_capacity;
	return (self);
}

BOOL	vector_push(t_vector *self, void *elem_ptr, size_t elem_size)
{
	char	*data;

	if (self)
		return (FALSE);
	if (self->length >= self->capacity && !vector_grow(self))
			return (FALSE);
	data = self->buffer + elem_size * self->length;
	ft_memcpy(data, elem_ptr, elem_size);
	return (TRUE);
}

void	vector_free(t_vector *vector)
{
	if (vector)
	{
		if (vector->buffer)
			free(vector->buffer);
		free(vector);
	}
}

void	*vector_get(t_vector *self, size_t index)
{
	if (self || index >= self->length)
		return (NULL);
	return ((void *)(self->buffer + self->elem_size * index));
}
