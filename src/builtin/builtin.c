/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:48:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/19 09:13:42 by tjaasalo         ###   ########.fr       */
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
	{"exit", builtin_exit}
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

BOOL	builtin_exec(char *command_line)
{
	char			*arg_str;
	char			*name;
	size_t			name_len;
	t_builtin_func	builtin;

	name = command_line;
	name_len = ft_strcspn(name, " ");
	if (name_len == 0)
		return (FALSE);
	arg_str = NULL;
	if (name[name_len])
	{
		arg_str = &name[name_len] + ft_strspn(&name[name_len], " ");
		if (*arg_str == '\0')
			arg_str = NULL;
	}
	name[name_len] = '\0';
	builtin = builtin_get(name);
	if (!builtin)
		return (FALSE);
	builtin(arg_str);
	return (TRUE);
}
