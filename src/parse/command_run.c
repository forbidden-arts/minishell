/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:47:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/12 18:49:39 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "command.h"

static BOOL	_command_run_builtin(
				t_command *self,
				int *stdin_fd,
				int *stdout_fd,
				t_env *env);

BOOL	command_run_builtin(t_command *self, t_env *env)
{
	int				stdin_fd;
	int				stdout_fd;
	BOOL			ok;

	ok = _command_run_builtin(self, &stdin_fd, &stdout_fd, env);
	if (stdin_fd > 0)
		close(stdin_fd);
	if (stdout_fd > 0)
		close(stdout_fd);
	return (ok);
}

static BOOL	_command_run_builtin(
	t_command *self,
	int *stdin_fd,
	int *stdout_fd,
	t_env *env)
{
	*stdin_fd = dup(STDIN_FILENO);
	if (*stdin_fd < 0)
		return (FALSE);
	*stdout_fd = dup(STDOUT_FILENO);
	if (*stdout_fd < 0)
		return (FALSE);
	command_redirect(self);
	self->status = self->builtin(self->args, env);
	dup2(*stdin_fd, STDIN_FILENO);
	dup2(*stdout_fd, STDOUT_FILENO);
	return (TRUE);
}
