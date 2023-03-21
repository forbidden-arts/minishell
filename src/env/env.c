/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:46:05 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/21 14:42:46 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "env.h"

static BOOL	_env_init(t_env *env, char **envp);

BOOL	env_init(char **envp)
{
	if (!_env_init(&g_shell.env, envp))
	{
		env_free();
		return (FALSE);
	}
	return (TRUE);
}

static BOOL	_env_init(t_env *env, char **envp)
{
	env->envp = vector_with_capacity(33, sizeof(char *));
	env->exports = vector_with_capacity(1, sizeof(char *));
	if (!env->envp || !env->exports)
		return (FALSE);
	while (*envp)
	{
		if (!vector_push(env->envp, envp++))
			return (FALSE);
	}
	return (TRUE);
}

void	env_free(void)
{
	vector_free(g_shell.env.envp);
	vector_free(g_shell.env.exports);
	g_shell.env = (t_env){0};
}
