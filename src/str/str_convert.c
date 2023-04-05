/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:22:02 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/04/05 16:58:05 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "str.h"

t_str	*str_from_ptr(const char *str)
{
	size_t	length;
	t_str	*self;

	length = ft_strlen(str) + 1;
	if (length <= 1)
		return (NULL);
	self = malloc(sizeof(t_str));
	if (!self)
		return (NULL);
	*self = (t_str){0};
	self->buffer = malloc(sizeof(char) * length);
	if (!self->buffer)
	{
		free(self);
		return (NULL);
	}
	ft_memcpy(self->buffer, str, length);
	self->length = length;
	self->capacity = length;
	return (self);
}

char	*str_as_ptr(t_str *self)
{
	return (self->buffer);
}
