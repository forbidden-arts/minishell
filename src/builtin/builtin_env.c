/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:34:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/01 16:22:02 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "builtin.h"

int	builtin_env(t_vector *argv, t_env *env)
{
	size_t	idx;

	(void)argv;
	idx = 0;
	while (idx < env->length)
	{
		printf("%s\n", *(char **)vector_get(env, idx));
		idx++;
	}
	return (EXIT_SUCCESS);
}
