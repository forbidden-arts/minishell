/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 04:07:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/25 13:39:34 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "command.h"
#include "parse.h"

static void	parser_free(t_parser *self);

t_vector	*parser_commands(t_parser *self)
{
	t_vector	*commands;

	commands = self->commands;
	self->commands = NULL;
	return (commands);
}

int	parse(const char *line, const t_env *env, t_vector **commands)
{
	t_parser	parser;
	int			status;

	parser = (t_parser){0};
	status = tokenize(line, &parser.tokens);
	if (status == EXIT_SUCCESS)
		status = tokens_validate(parser.tokens);
	if (status == EXIT_SUCCESS)
		status = tokens_expand(&parser.tokens, env);
	if (status == EXIT_SUCCESS)
		status = commands_from_tokens(parser.tokens, &parser.commands);
	if (status == EXIT_SUCCESS)
		status = commands_init(parser.tokens, parser.commands);
	if (status == EXIT_SUCCESS)
		*commands = parser_commands(&parser);
	parser_free(&parser);
	return (status);
}

static void	parser_free(t_parser *self)
{
	if (self->tokens)
		tokens_free(self->tokens);
	if (self->commands)
		commands_free(self->commands);
	*self = (t_parser){0};
}
