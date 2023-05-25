/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:07:29 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/25 14:10:42 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <signal.h>
#include <sys/ioctl.h>
#include "shell.h"

t_shell	g_shell;

void	handle_int(int signum)
{
	(void)signum;
	if (!g_shell.is_waiting)
	{
		g_shell.eof = TRUE;
		rl_replace_line("", 0);
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_on_new_line();
	}
}

BOOL	state_init(t_state *self, char **envp)
{
	struct sigaction	action;

	*self = (t_state){0};
	self->env = env_init(envp);
	if (!self->env)
		return (FALSE);
	self->termios_state = termios_init();
	if (!self->termios_state && g_shell.status)
	{
		env_free(&self->env);
		return (FALSE);
	}
	action.sa_flags = 0;
	sigemptyset(&action.sa_mask);
	action.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &action, NULL);
	action.sa_handler = handle_int;
	sigaction(SIGINT, &action, NULL);
	g_shell.eof = FALSE;
	return (TRUE);
}

void	state_free(t_state *self)
{
	if (self->termios_state)
		free(self->termios_state);
	if (self->env)
		env_free(&self->env);
}
