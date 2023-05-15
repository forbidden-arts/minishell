/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:59:23 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/12 21:34:59 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "command.h"

static BOOL	_error_cmd_not_found(const char *name);

void	command_redirect(t_command *self)
{
	if (self->input_fd)
	{
		dup2(self->input_fd, STDIN_FILENO);
		close(self->input_fd);
	}
	if (self->output_fd)
	{
		dup2(self->output_fd, STDOUT_FILENO);
		close(self->output_fd);
	}
}

BOOL	command_resolve(t_command *self, const t_env *env)
{
	t_path	*path;
	char	*name;

	name = self->name.value;
	if (!self->name.is_path)
	{
		path = path_from_env(env);
		if (!path)
		{
			perror("minishell");
			return (FALSE);
		}
		self->name.value = path_which(path, name);
		path_free(path);
		if (!self->name.value)
			return (_error_cmd_not_found(name));
		return (TRUE);
	}
	if (access(self->name.value, X_OK))
	{
		perror("minishell");
		return (FALSE);
	}
	return (TRUE);
}

static BOOL	_error_cmd_not_found(const char *name)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, name, ft_strlen(name));
	write(STDERR_FILENO, ": command not found\n", 20);
	return (FALSE);
}
