/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:10:20 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/04/20 14:06:04 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "builtin.h"
#include "libft.h"
#include "ft.h"
#include "shell.h"
#include "vector.h"
#include "bool.h"
#include "parse.h"
#include "main.h"

static BOOL	_parse_args(char *line, t_vector *args);

int	main(int argc, char **argv, char **envp)
{
	t_vector	*args;

	(void)argc;
	(void)argv;
	shell_init(envp);
	while (1)
	{
		g_shell.line = readline("> ");
		if (!g_shell.line)
			builtin_exit(NULL);
		t_vector *tokens = tokenize(g_shell.line);
		expand(tokens);
		for (size_t i = 0; i < tokens->length; i++)
		{
			t_token *token = vector_get(tokens, i);
			if (token->type == token_type_word)
				printf("index:: %zu word: %s\n", i, token->word);
		}
		if (g_shell.line[0])
			add_history(g_shell.line);
		args = parse_args(g_shell.line);
		if (args)
			g_shell.status = builtin_exec(args);
		vector_free(args);
		free(g_shell.line);
		g_shell.line = NULL;
	}
	rl_clear_history();
	shell_free();
	return (0);
}

t_vector	*parse_args(char *line)
{
	t_vector	*args;

	args = vector_with_capacity(1, sizeof(char *));
	if (!args)
		return (NULL);
	if (!_parse_args(line, args))
	{
		vector_free(args);
		return (NULL);
	}
	return (args);
}

static BOOL	_parse_args(char *line, t_vector *args)
{
	char		*arg;

	arg = ft_strtok(line, " ");
	while (arg)
	{
		if (!vector_push(args, &arg))
			return (FALSE);
		arg = ft_strtok(NULL, " ");
	}
	return (TRUE);
}
