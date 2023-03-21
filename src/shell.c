/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:07:29 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/20 19:38:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

t_shell	g_shell;

void	shell_init(char **envp)
{
	env_init(envp);
}

void	free_shell(void)
{
	if (g_shell.line)
		free(g_shell.line);
	env_free();
}
