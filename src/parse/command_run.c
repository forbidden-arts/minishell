/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:47:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/25 13:26:43 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "command.h"

static void	_command_run_builtin(
				t_command *self,
				int *stdin_fd,
				int *stdout_fd,
				t_env *env);

void	command_run_builtin(t_command *self, t_env *env)
{
	int				stdin_fd;
	int				stdout_fd;

	_command_run_builtin(self, &stdin_fd, &stdout_fd, env);
	if (stdin_fd > 0)
		close(stdin_fd);
	if (stdout_fd > 0)
		close(stdout_fd);
	return ;
}

static void	_command_run_builtin(
	t_command *self,
	int *stdin_fd,
	int *stdout_fd,
	t_env *env)
{
	*stdin_fd = dup(STDIN_FILENO);
	if (*stdin_fd < 0)
		return ;
	*stdout_fd = dup(STDOUT_FILENO);
	if (*stdout_fd < 0)
		return ;
	command_redirect(self);
	self->status = self->builtin(self->args, env);
	dup2(*stdin_fd, STDIN_FILENO);
	dup2(*stdout_fd, STDOUT_FILENO);
	return ;
}
