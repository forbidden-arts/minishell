/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:09 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/23 13:48:00 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ft.h"
#include "libft.h"
#include "env.h"
#include "shell.h"
#include "builtin.h"

static int	_builtin_unset(char *name, t_env *env);

int	builtin_unset(t_vector *argv, t_env *env)
{
	size_t	idx;
	int		status;

	idx = 1;
	status = 0;
	while (idx < argv->length)
		status |= _builtin_unset(*(char **)vector_get(argv, idx++), env);
	return (status);
}

static int	_builtin_unset(char *name, t_env *env)
{
	if (!is_name(name, (size_t)-1))
	{
		write(STDERR_FILENO, "minishell: unset: `", 20);
		write(STDERR_FILENO, name, ft_strlen(name));
		write(STDERR_FILENO, "': not a valid identifier\n", 26);
		return (EXIT_FAILURE);
	}
	env_unset(env, name);
	return (EXIT_SUCCESS);
}
