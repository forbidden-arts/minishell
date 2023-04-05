/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:12:07 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/04/05 15:21:55 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "str.h"

BOOL	str_push(t_str *self, char c)
{
	if (self->length >= self->capacity && !str_grow(self))
		return (FALSE);
	self->buffer[self->length - 1] = c;
	self->buffer[self->length] = '\0';
	self->length++;
	return (TRUE);
}

BOOL	str_push_ptr(t_str *self, const char *str)
{
	size_t	length;

	length = ft_strlen(str);
	if (length == 0)
		return (FALSE);
	if (self->capacity - self->length < length)
	{
		if (!str_reserve(self, length - (self->capacity - self->length)))
			return (FALSE);
	}
	ft_memcpy(&self->buffer[self->length - 1], str, length);
	self->length += length;
	self->buffer[self->length - 1] = '\0';
	return (TRUE);
}
