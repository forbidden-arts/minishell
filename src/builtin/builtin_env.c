/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:34:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/27 13:07:13 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "shell.h"
#include "builtin.h"

int	builtin_env(t_vector *argv)
{
	size_t	idx;

	(void)argv;
	idx = 0;
	while (idx < g_shell.env->length)
	{
		printf("%s\n", *(char **)vector_get(g_shell.env, idx));
		idx++;
	}
	return (OK);
}
