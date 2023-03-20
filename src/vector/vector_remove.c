/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 03:26:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/20 14:32:51 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"

void	vector_swap_remove(t_vector *self, size_t index)
{
	char	*data;
	char	*last;

	if (index == self->length - 1)
		ft_bzero(self->buffer, self->elem_size);
	else
	{
		data = &self->buffer[self->elem_size * index];
		last = &self->buffer[self->elem_size * (self->length - 1)];
		ft_memcpy(data, last, self->elem_size);
	}
	self->length--;
}
