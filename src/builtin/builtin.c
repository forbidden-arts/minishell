/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:48:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/16 08:21:28 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "libft.h"
#include "ft.h"
#include "error.h"
#include "builtin.h"

t_builtin_func	builtin_get(char *name)
{
	size_t					idx;
	static const t_builtin	builtins[BUILTINS_LENGTH] = {
	{"pwd", builtin_pwd},
	{"env", builtin_env},
	{"exit", builtin_exit},
	{"export", builtin_export},
	{"unset", builtin_unset},
	{"cd", builtin_cd},
	{"echo", builtin_echo}
	};

	idx = 0;
	while (idx < BUILTINS_LENGTH)
	{
		if (ft_strncmp(name, builtins[idx].name, 8) == 0)
			return (builtins[idx].func);
		idx++;
	}
	return (NULL);
}

int	builtin_exec(t_vector *argv, t_env *env)
{
	char			*name;
	t_builtin_func	builtin;

	if (argv->length == 0)
		return (EXIT_NOT_FOUND);
	name = *(char **)vector_get(argv, 0);
	builtin = builtin_get(name);
	if (!builtin)
		return (EXIT_NOT_FOUND);
	return (builtin(argv, env));
}
