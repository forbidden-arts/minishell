/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:34:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/23 17:44:43 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "shell.h"
#include "builtin.h"

int	builtin_env(char *arg_str)
{
	size_t	idx;

	(void)arg_str;
	idx = 0;
	while (idx < g_shell.env.envp->length)
	{
		printf("%s\n", *(char **)vector_get(g_shell.env.envp, idx));
		idx++;
	}
	return (OK);
}
