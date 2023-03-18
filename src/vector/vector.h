/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:49:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/19 00:55:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>

typedef struct s_vector
{
	char	*buffer;
	size_t	capacity;
	size_t	length;
	size_t	elem_size;
}	t_vector;

t_vector	*vector_with_capacity(size_t capacity, size_t elem_size);
t_vector	*vector_grow(t_vector *self);
void		vector_free(t_vector *vector);
BOOL		vector_push(t_vector *self, void *elem_ptr, size_t elem_size);
void		*vector_get(t_vector *self, size_t index);

#endif
