/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:49:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/19 05:07:00 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <sys/types.h>
# include "bool.h"

# define INVALID_INDEX -1

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
BOOL		vector_push(t_vector *self, void *elem_ptr);
void		*vector_get(t_vector *self, size_t index);

///			Searches for an element in the vector, returning its index.
///
///			@param self Non-null pointer to a vector.
///			@param cmp Non-null function used to compare each element.
///			@param param Non-null 2nd parameter passed to cmp.
///
///			@return
///			Index of the first matching element if found or INVALID_INDEX.
ssize_t		vector_position(
				t_vector *self,
				BOOL (*cmp)(void *, void *),
				void *param);

///			Removes an element from the vector, swapping it with the last
///			element when possible.
///
///			@param self Non-null pointer to a vector.
///			@param index Index of the element to be removed.
void		vector_swap_remove(t_vector *self, size_t index);

#endif
