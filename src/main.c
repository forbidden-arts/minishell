/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:10:20 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/01 16:22:10 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "builtin.h"
#include "shell.h"
#include "command.h"
#include "error.h"
#include "main.h"

t_line	prompt(const t_termios *termios_state)
{
	t_line	line;

	line = (t_line){0};
	termios_echoctl_disable(termios_state);
	line.inner = readline("minishell> ");
	if (!line.inner)
		line.is_eof = TRUE;
	else if (!*(line.inner))
	{
		line.is_empty = TRUE;
		free(line.inner);
	}
	return (line);
}

void	_run(
	const char *line,
	t_env *env,
	t_vector **commands,
	t_termios *termios_state)
{
	add_history(line);
	g_shell.status = parse(line, env, commands);
	termios_echoctl_reset(termios_state);
	if (g_shell.status == EXIT_EMPTY)
	{
		g_shell.status = EXIT_SUCCESS;
		return ;
	}
	if (g_shell.status != EXIT_SUCCESS)
		return ;
	g_shell.is_waiting = TRUE;
	commands_exec(*commands, env);
	g_shell.status = commands_status(*commands);
	g_shell.is_waiting = FALSE;
}

void	run(const char *line, t_env *env, t_termios *termios_state)
{
	t_vector	*commands;

	commands = NULL;
	_run(line, env, &commands, termios_state);
	commands_free(commands);
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
		run(line.inner, state.env, state.termios_state);
		if (g_shell.status & EXIT_PRINT_FLAG)
			print_error(g_shell.status);
		free(line.inner);
		if (g_shell.status & EXIT_FATAL)
			break ;
	}
	state_free(&state);
	rl_clear_history();
	return (g_shell.status & (~EXIT_FATAL));
}
