/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:46:05 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/11 11:35:19 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "env.h"

static BOOL	_env_init(t_env *env, char **envp);

t_env	*env_init(char **envp)
{
	t_env	*env;

	env = vector_with_capacity(33, sizeof(char *));
	if (!env)
		return (NULL);
	if (!_env_init(env, envp))
	{
		env_free(&env);
		return (NULL);
	}
	return (env);
}

static BOOL	_env_init(t_env *env, char **envp)
{
	char	*var;

	while (*envp)
	{
		var = ft_strdup(*envp);
		if (!var)
			return (FALSE);
		if (!vector_push(env, &var))
		{
			free(var);
			return (FALSE);
		}
		envp++;
	}
	return (TRUE);
}

void	env_free(t_env **env)
{
	size_t	idx;
	char	*var;

	idx = 0;
	while (idx < (*env)->length)
	{
		var = *(char **)vector_get(*env, idx);
		free(var);
		idx++;
	}
	vector_free(*env);
	env = NULL;
}

t_env	*env_clone(const t_env *self)
{
	t_env	*clone;
	size_t	index;
	char	*var;

	clone = vector_with_capacity(self->capacity, self->elem_size);
	if (!clone)
		return (NULL);
	index = 0;
	while (index < self->length)
	{
		var = ft_strdup(*(char **)vector_get(self, index));
		if (!var)
			env_free(&clone);
		vector_push(clone, &var);
		index++;
	}
	return (clone);
}
