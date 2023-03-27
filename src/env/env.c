/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:46:05 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/23 17:13:51 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "env.h"

static BOOL	_env_init(t_env **env, char **envp);

BOOL	env_init(char **envp)
{
	if (!_env_init(&g_shell.env, envp))
	{
		env_free();
		return (FALSE);
	}
	return (TRUE);
}

static BOOL	_env_init(t_env **env, char **envp)
{
	char	*var;

	*env = vector_with_capacity(33, sizeof(char *));
	if (!*env)
		return (FALSE);
	while (*envp)
	{
		var = ft_strdup(*envp);
		if (!var || !vector_push(*env, &var))
			return (FALSE);
		envp++;
	}
	return (TRUE);
}

void	env_free(void)
{
	size_t	idx;
	char	*var;

	idx = 0;
	while (idx < g_shell.env->length)
	{
		var = *(char **)vector_get(g_shell.env, idx);
		free(var);
		idx++;
	}
	vector_free(g_shell.env);
	g_shell.env = NULL;
}
