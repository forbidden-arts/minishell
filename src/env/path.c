/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:16:47 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/11 11:49:14 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "ft.h"
#include "str.h"
#include "env.h"

t_path	*path_from_env(const t_env *env)
{
	t_path	*self;
	char	*env_path;
	char	*path;

	self = vector_with_capacity(1, sizeof(char *));
	if (!self)
		return (NULL);
	env_path = (char *)env_get(env, "PATH");
	if (!env_path)
		return (self);
	env_path = ft_strdup(env_path);
	if (!env_path)
	{
		vector_free(self);
		return (NULL);
	}
	vector_push(self, &env_path);
	path = ft_strtok(env_path, ":");
	while (path)
	{
		if (!vector_push(self, &path))
			path_free(self);
		path = ft_strtok(NULL, ":");
	}
	return (self);
}

void	path_free(t_path *self)
{
	if (self)
	{
		if (self->length >= 1)
			free(vector_get(self, 0));
		vector_free(self);
	}
}

static t_str	*str_from_pathname(const char *path, const char *name)
{
	t_str	*self;

	self = str_from_ptr(path);
	if (!self)
		return (NULL);
	if (!str_push(self, '/') || !str_push_ptr(self, name))
	{
		str_free(self);
		return (NULL);
	}
	return (self);
}

char	*path_which(t_path *self, const char *name)
{
	t_str	*str;
	size_t	index;

	index = 1;
	while (index < self->length)
	{
		str = str_from_pathname(*(char **)vector_get(self, index), name);
		if (!str)
		{
			perror("minishell");
			return (NULL);
		}
		if (access(str->buffer, X_OK) == 0)
			return (str_as_ptr(str));
		index++;
	}
	return (NULL);
}
