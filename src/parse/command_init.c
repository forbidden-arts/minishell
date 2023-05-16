/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 07:13:13 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/16 06:15:35 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "error.h"
#include "command.h"

void	command_operator(
	t_command *self,
	t_operator operator,
	t_tokens_iter *iter)
{
	t_token	*token;

	token = tokens_next(iter);
	if (operator == operator_infile)
		command_redirect_input(self, token->word, FALSE);
	else if (operator == operator_heredoc)
		command_redirect_input(self, token->word, TRUE);
	else if (operator == operator_outfile_truncate)
		command_redirect_output(self, token->word, FALSE);
	else if (operator == operator_outfile_append)
		command_redirect_output(self, token->word, TRUE);
}

int	command_name(t_command *self)
{
	if (self->args->length < 1)
		return (EXIT_SYNTAX);
	self->name.value = *(char **)vector_get(self->args, 0);
	self->name.is_path = TRUE;
	if (ft_strchr(self->name.value, '/'))
		return (EXIT_SUCCESS);
	self->name.is_path = FALSE;
	self->builtin = builtin_get(self->name.value);
	return (EXIT_SUCCESS);
}

int	command_init(t_command *self, t_tokens_iter *tokens)
{
	t_token	*token;
	char	*arg;

	token = tokens_next(tokens);
	while (token)
	{
		if (token->type == token_type_word)
		{
			arg = ft_strdup(token->word);
			if (!arg)
				return (EXIT_ERRNO);
			if (!vector_push(self->args, &arg))
			{
				free(arg);
				return (EXIT_ERRNO);
			}
		}
		else if (token->operator == operator_pipe)
			break ;
		else
			command_operator(self, token->operator, tokens);
		token = tokens_next(tokens);
	}
	return (command_name(self));
}

int	commands_init(t_tokens *tokens, t_vector *commands)
{
	t_tokens_iter	iter;
	size_t			index;
	t_command		*command;
	int				status;

	index = 0;
	tokens_iter(&iter, tokens);
	while (index < commands->length)
	{
		command = vector_get(commands, index);
		status = command_init(command, &iter);
		if (status != EXIT_SUCCESS)
			return (status);
		index++;
	}
	return (EXIT_SUCCESS);
}
