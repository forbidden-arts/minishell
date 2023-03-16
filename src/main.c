/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:10:20 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/16 13:13:38 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "builtin.h"
#include "libft.h"
#include "ft.h"
#include "main.h"

int	main(void)
{
	while (1)
	{
		g_shell.line = readline("> ");
		exec_builtin(g_shell.line);
	}
	return (0);
}

BOOL	exec_builtin(char *command_line)
{
	char	*arg_str;
	char	*cmd;
	size_t	cmd_len;

	cmd = command_line;
	cmd_len = ft_strcspn(cmd, " ");
	if (cmd_len == 0)
		return (FALSE);
	arg_str = NULL;
	if (cmd[cmd_len])
		arg_str = &cmd[cmd_len] + ft_strspn(&cmd[cmd_len], " ");
	if (*arg_str == '\0')
		arg_str = NULL;
	cmd[cmd_len] = '\0';
	if (ft_strncmp("exit", cmd, cmd_len) == 0)
		builtin_exit(arg_str);
	else if (ft_strncmp("pwd", cmd, cmd_len) == 0)
		builtin_pwd(arg_str);
	else if (ft_strncmp("env", cmd, cmd_len) == 0)
		builtin_env(arg_str);
	else
		return (FALSE);
	return (TRUE);
}

void	free_shell(void)
{
	if (g_shell.line)
		free(g_shell.line);
}
