/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:34:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/23 14:23:05 by tjaasalo         ###   ########.fr       */
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
