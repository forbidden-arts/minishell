/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:27:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/19 01:08:30 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
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
	exit_code = ft_strtonum(arg_str, int_min(), int_max(), &err_str);
	printf("exit\n");
	if (err_str)
	{
		exit_code = EXIT_FAILURE;
		printf("minishell: exit: %s: numeric argument required", arg_str);
	}
	free_shell();
	exit(exit_code);
}
