/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:43:40 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/27 14:46:08 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "ft.h"
#include "env.h"
#include "shell.h"
#include "builtin.h"

static int	_builtin_export(char *var)
{
	size_t	name_length;

	name_length = ft_strcspn(var, "=");
	if (name_length == 0 || !is_name(var, name_length))
	{
		write(STDERR_FILENO, "minishell: export: `", 20);
		write(STDERR_FILENO, var, name_length);
		write(STDERR_FILENO, "': not a valid identifier\n", 26);
		return (ERR_INVALID_ARGS);
	}
	if (!var[name_length])
		return (ERR_INVALID_ARGS);
	var[name_length] = '\0';
	if (!env_set(var, &var[name_length + 1]))
	{
		perror("minishell: export");
		return (ERR_SYSTEM);
	}
	return (OK);
}

int	builtin_export(t_vector *argv)
{
	char	*var;
	size_t	idx;
	int		status;

	if (argv->length <= 1)
		return (builtin_env(argv));
	status = OK;
	idx = 1;
	while (idx < argv->length)
	{
		var = *(char **)vector_get(argv, idx++);
		status |= _builtin_export(var); // TODO: Needs early return on err sys
	}
	return (status);
}
