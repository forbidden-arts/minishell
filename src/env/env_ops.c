/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:27:24 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/20 19:39:41 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "env.h"

const char	*env_get(const char *name)
{
	t_env_match	match;
	ssize_t		idx;

	match.name = name;
	match.name_length = ft_strlen(name);
	idx = env_position(g_shell.env.envp, &match);
	if (idx == INVALID_INDEX)
		return (NULL);
	return (*(char **)vector_get(g_shell.env.envp, (size_t)idx));
}

void	env_unset(const char *name)
{
	t_env_match	match;
	ssize_t		idx;

	match.name = name;
	match.name_length = ft_strlen(name);
	idx = env_position(g_shell.env.envp, &match);
	if (idx == INVALID_INDEX)
		return ;
	vector_swap_remove(g_shell.env.envp, (size_t)idx);
	idx = env_position(g_shell.env.exports, &match);
	if (idx != INVALID_INDEX)
	{
		free(*(char **)vector_get(g_shell.env.exports, (size_t)idx));
		vector_swap_remove(g_shell.env.exports, (size_t)idx);
	}
}

BOOL	env_set(const char *name, const char *value)
{
	char	*var;
	size_t	name_length;
	size_t	value_length;
	size_t	var_length;

	name_length = ft_strlen(name);
	value_length = ft_strlen(value);
	var_length = name_length + value_length + 1;
	var = malloc(sizeof(char) * var_length + 1);
	if (!var)
		return (FALSE);
	env_unset(name);
	ft_memcpy(var, name, name_length);
	var[name_length] = '=';
	ft_memcpy(&var[name_length + 1], value, value_length);
	var[var_length] = '\0';
	if (!vector_push(g_shell.env.envp, &var)
		|| !vector_push(g_shell.env.exports, &var))
		return (FALSE);
	return (TRUE);
}
