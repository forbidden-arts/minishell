/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:48:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/23 22:03:21 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "libft.h"
#include "ft.h"
#include "builtin.h"

t_builtin_func	builtin_get(char *name)
{
	size_t					idx;
	static const t_builtin	builtins[BUILTINS_LENGTH] = {
	{"pwd", builtin_pwd},
	{"env", builtin_env},
	{"exit", builtin_exit},
	{"export", builtin_export},
	{"unset", builtin_unset}
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

int	builtin_exec(t_vector *argv)
{
	char			*name;
	t_builtin_func	builtin;

	if (argv->length == 0)
		return (ERR_NOT_FOUND);
	name = *(char **)vector_get(argv, 0);
	builtin = builtin_get(name);
	if (!builtin)
		return (ERR_NOT_FOUND);
	return (builtin(argv));
}
