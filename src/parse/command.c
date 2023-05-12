/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 04:28:58 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/12 21:33:15 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "parse.h"
#include "util.h"
#include "command.h"

BOOL	command_new(t_command *self)
{
	*self = (t_command){0};
	self->args = vector_with_capacity(1, sizeof(char *));
	if (!self->args)
	{
		free(self);
		return (FALSE);
	}
	return (TRUE);
}

void	command_free(t_command *self)
{
	size_t	index;

	if (self)
	{
		if (!self->builtin && !self->name.is_path && self->name.value)
			free(self->name.value);
		if (self->args)
		{
			index = 0;
			while (index < self->args->length)
				free(*(char **)vector_get(self->args, index++));
			vector_free(self->args);
		}
		close_safe(&self->input_fd);
		close_safe(&self->output_fd);
		*self = (t_command){0};
	}
}
