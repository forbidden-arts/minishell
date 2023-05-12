/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_wait.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:00:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/12 19:08:51 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>
#include "shell.h"
#include "command.h"

#define EXIT_CHILD_SIGNALED 200
#define EXIT_UNREACHABLE 300

int	commands_status(t_vector *commands)
{
	size_t		index;
	t_command	*command;

	index = 0;
	while (index < commands->length)
	{
		command = vector_get(commands, index);
		command_wait(command);
		index++;
	}
	return (command->status);
}

// TODO: Set status from signal
///		Waits for the given commands exit status to become available, if it was
///		executed in a child process.
void	command_wait(t_command *self)
{
	int	status;
	int	signal;

	if (self->pid == 0)
		return ;
	status = 0;
	self->status = EXIT_UNREACHABLE;
	if (self->pid > 0)
	{
		if (waitpid(self->pid, &status, 0) > 0)
		{
			if (WIFEXITED(status))
				self->status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
			{
				signal = WTERMSIG(status);
				self->status = signal;
			}
		}
		else
			printf("\n");
	}
}
