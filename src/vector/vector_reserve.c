/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:41:09 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/10 22:58:23 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "vector.h"

BOOL	vector_reserve(t_vector *self, size_t additional_capacity)
{
	size_t	target_capacity;
	size_t	new_capacity;
	char	*buffer;

	target_capacity = self->length + additional_capacity;
	if (target_capacity <= self->capacity)
		return (TRUE);
	new_capacity = self->capacity;
	while (new_capacity < target_capacity)
		new_capacity *= 2;
	buffer = malloc(new_capacity * self->elem_size);
	if (!buffer)
		return (FALSE);
	ft_memcpy(buffer, self->buffer, self->length * self->elem_size);
	free(self->buffer);
	self->buffer = buffer;
	self->capacity = new_capacity;
	return (TRUE);
}
