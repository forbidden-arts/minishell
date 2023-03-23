/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:10:20 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/23 17:53:38 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "builtin.h"
#include "libft.h"
#include "ft.h"
#include "shell.h"
#include "main.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	shell_init(envp);
	while (1)
	{
		g_shell.line = readline("> ");
		g_shell.status = builtin_exec(g_shell.line);
		free(g_shell.line);
		g_shell.line = NULL;
	}
	free_shell();
	return (0);
}
