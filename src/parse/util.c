/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:55:17 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/25 13:50:16 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "util.h"

void	close_safe(int *fd)
{
	if (fd)
	{
		if (*fd > 1)
			close(*fd);
		*fd = 0;
	}
}

char	**argv_from_vector(t_vector **vector)
{
	char	*null;
	char	**argv;

	null = NULL;
	if (!vector_push(*vector, &null))
		return (NULL);
	argv = (char **)(*vector)->buffer;
	free(*vector);
	*vector = NULL;
	return (argv);
}

void	argv_free(char **argv)
{
	char	**head;

	if (argv)
	{
		head = argv;
		while (*head)
			free(*(head++));
		free(argv);
	}
}

char	**envp_from_env(const t_env *env)
{
	char		**envp;
	t_env		*clone;

	clone = env_clone(env);
	if (!clone)
		return (NULL);
	envp = argv_from_vector(&clone);
	if (!envp)
		env_free(&clone);
	return (envp);
}
