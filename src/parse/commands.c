/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 07:07:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/09 14:59:55 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "command.h"

static BOOL		_commands_from_tokens(t_vector *commands);
static size_t	pipe_count(t_tokens *tokens);
static BOOL		pipe_connect(t_command *lhs, t_command *rhs);

t_vector	*commands_from_tokens(t_tokens *tokens)
{
	size_t		commands_length;
	t_vector	*commands;

	commands_length = pipe_count(tokens) + 1;
	commands = vector_with_capacity(commands_length, sizeof(t_command));
	if (!commands)
		return (NULL);
	if (!_commands_from_tokens(commands))
	{
		commands_free(commands);
		return (NULL);
	}
	return (commands);
}

static BOOL	_commands_from_tokens(t_vector *commands)
{
	size_t		index;
	t_command	command;
	t_command	*previous;

	if (!command_new(&command))
		return (FALSE);
	vector_push(commands, &command);
	index = 1;
	while (index < commands->capacity)
	{
		previous = vector_get(commands, index - 1);
		if (!command_new(&command))
			return (FALSE);
		if (!pipe_connect(previous, &command))
			return (FALSE);
		vector_push(commands, &command);
		index++;
	}
	return (TRUE);
}

void	commands_free(t_vector *self)
{
	size_t		index;
	t_command	*command;

	if (self)
	{
		index = 0;
		while (index < self->length)
		{
			command = vector_get(self, index);
			command_free(command);
			index++;
		}
		vector_free(self);
	}
}

static size_t	pipe_count(t_tokens *tokens)
{
	size_t	index;
	size_t	count;
	t_token	*token;

	index = 0;
	count = 0;
	while (index < tokens->length)
	{
		token = vector_get(tokens, index++);
		if (token->type == token_type_operator)
		{
			if (token->operator == operator_pipe)
				count++;
		}
	}
	return (count);
}

static BOOL	pipe_connect(t_command *lhs, t_command *rhs)
{
	int	fd[2];

	if (pipe(fd) < 0)
		return (FALSE);
	lhs->output_fd = fd[1];
	rhs->input_fd = fd[0];
	return (TRUE);
}
