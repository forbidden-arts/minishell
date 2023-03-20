/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:27:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/20 10:59:50 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "ft.h"
#include "shell.h"
#include "builtin.h"

static int	int_max(void)
{
	return ((int)(((unsigned int)-1) / 2));
}

static int	int_min(void)
{
	return ((int)(((((unsigned int)-1) / 2) + 1)));
}

void	builtin_exit(char *arg_str)
{
	int			exit_code;
	const char	*err_str;

	err_str = NULL;
	if (!arg_str)
		exit_code = EXIT_SUCCESS;
	else
		exit_code = ft_strtonum(arg_str, int_min(), int_max(), &err_str);
	if (err_str)
	{
		exit_code = EXIT_FAILURE;
		write(STDERR_FILENO, "exit\n", 5);
		write(STDERR_FILENO, "minishell: exit: ", 17);
		write(STDERR_FILENO, arg_str, ft_strlen(arg_str));
		write(STDERR_FILENO, ": numeric argument required\n", 28);
	}
	else
		printf("exit\n");
	free_shell();
	exit(exit_code);
}
