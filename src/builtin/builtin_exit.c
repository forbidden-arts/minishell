/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:27:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/23 22:03:34 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

int	builtin_exit(t_vector *argv)
{
	const char	*err_str;
	int			exit_code;
	char		*arg;

	err_str = NULL;
	if (argv->length <= 1)
		exit_code = EXIT_SUCCESS;
	else
	{
		arg = *(char **)vector_get(argv, 1);
		exit_code = ft_strtonum(arg, int_min(), int_max(), &err_str);
	}
	write(STDERR_FILENO, "exit\n", 5);
	if (err_str)
	{
		exit_code = EXIT_FAILURE;
		write(STDERR_FILENO, "minishell: exit: ", 17);
		write(STDERR_FILENO, arg, ft_strlen(arg));
		write(STDERR_FILENO, ": numeric argument required\n", 28);
	}
	vector_free(argv);
	free_shell();
	exit(exit_code);
	return (OK);
}
