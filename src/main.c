/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:10:20 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/16 08:18:51 by tjaasalo         ###   ########.fr       */
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
#include "command.h"
#include <termios.h>
#include <signal.h>
#include <unistd.h>
#include "error.h"
#include "main.h"

typedef struct s_line
{
	char	*inner;
	BOOL	is_eof;
	BOOL	is_empty;
}	t_line;

t_line	prompt(const t_termios *termios_state)
{
	t_line	line;

	line = (t_line){0};
	termios_echoctl_disable(termios_state);
	line.inner = readline("minishell> ");
	termios_echoctl_reset(termios_state);
	if (!line.inner)
		line.is_eof = TRUE;
	else if (!*(line.inner))
	{
		line.is_empty = TRUE;
		free(line.inner);
	}
	return (line);
}

// TODO: Does this function need a return value? Do something if exec fails?
BOOL	run(const char *line, t_env *env)
{
	t_vector	*commands;

	add_history(line);
	g_shell.status = parse(line, env, &commands);
	if (g_shell.status != EXIT_SUCCESS)
		return (FALSE);
	if (!commands)
		return (FALSE);
	if (commands_exec(commands, env))
		g_shell.status = commands_status(commands);
	commands_free(commands);
	return (TRUE);
}

int	main(int argc, char **argv, char **envp)
{
	t_state	state;
	t_line	line;

	(void)argc;
	(void)argv;
	if (!state_init(&state, envp))
		return (g_shell.status);
	while (1)
	{
		line = prompt(state.termios_state);
		if (line.is_eof)
			break ;
		if (line.is_empty)
			continue ;
		run(line.inner, state.env);
		free(line.inner);
		if (g_shell.status & EXIT_FATAL)
			break ;
	}
	state_free(&state);
	rl_clear_history();
	return (g_shell.status & (~EXIT_FATAL));
}
