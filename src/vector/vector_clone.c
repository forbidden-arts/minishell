/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:40:53 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/08 19:45:49 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "vector.h"

t_vector	*vector_clone(const t_vector *self)
{
	t_vector	*clone;

	clone = vector_with_capacity(self->capacity, self->elem_size);
	if (!clone)
		return (NULL);
	ft_memcpy(clone->buffer, self->buffer, self->elem_size * self->length);
	clone->length = self->length;
	return (clone);
}
