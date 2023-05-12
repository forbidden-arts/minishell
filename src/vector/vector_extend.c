/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:05:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/10 22:34:31 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"

BOOL	vector_extend(t_vector *self, const t_vector *other)
{
	size_t	bytes_count;
	size_t	offset;

	if (self->elem_size != other->elem_size)
		return (FALSE);
	if (!vector_reserve(self, other->length))
		return (FALSE);
	bytes_count = other->elem_size * other->length;
	offset = self->length * other->elem_size;
	ft_memcpy(&self->buffer[offset], other->buffer, bytes_count);
	self->length += other->length;
	return (TRUE);
}
