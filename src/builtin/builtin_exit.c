/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:27:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/16 12:15:54 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "ft.h"
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
	int		exit_code;
	char	*err_str;

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
	free_line();
	exit(exit_code);
}
