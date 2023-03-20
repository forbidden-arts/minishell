/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 03:26:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/20 17:41:24 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "vector.h"

void	vector_swap_remove(t_vector *self, size_t index)
{
	char	*data;
	char	*last;
	size_t	last_idx;

	last_idx = self->length - 1;
	if (index == last_idx)
		ft_bzero(&self->buffer[self->elem_size * index], self->elem_size);
	else
	{
		data = &self->buffer[self->elem_size * index];
		last = &self->buffer[self->elem_size * last_idx];
		ft_memcpy(data, last, self->elem_size);
	}
	self->length--;
}
