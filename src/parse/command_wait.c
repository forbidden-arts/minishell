/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_wait.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:00:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/25 13:32:52 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "error.h"
#include "libft.h"
#include "command.h"

static void	print_error_termsig(int signum);

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

void	command_wait(t_command *self)
{
	int	status;
	int	signum;

	status = 0;
	if (self->pid > 0)
	{
		if (waitpid(self->pid, &status, 0) > 0)
		{
			if (WIFEXITED(status))
				self->status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
			{
				signum = WTERMSIG(status);
				print_error_termsig(signum);
				self->status = EXIT_TERMSIG + signum;
			}
		}
		else
			printf("\n");
	}
}

static void	print_error_termsig(int signum)
{
	ft_putstr_fd("Child terminated with signal ", STDERR_FILENO);
	ft_putnbr_fd(signum, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
