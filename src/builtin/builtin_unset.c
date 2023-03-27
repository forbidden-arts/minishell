/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:09 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/27 15:29:59 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ft.h"
#include "libft.h"
#include "env.h"
#include "shell.h"
#include "builtin.h"

static int	_builtin_unset(char *name);

int	builtin_unset(t_vector *argv)
{
	size_t	idx;
	int		status;

	idx = 1;
	status = 0;
	while (idx < argv->length)
		status |= _builtin_unset(*(char **)vector_get(argv, idx++));
	return (status);
}

static int	_builtin_unset(char *name)
{
	if (!is_name(name, (size_t)-1))
	{
		write(STDERR_FILENO, "minishell: unset: `", 20);
		write(STDERR_FILENO, name, ft_strlen(name));
		write(STDERR_FILENO, "': not a valid identifier\n", 26);
		return (ERR_INVALID_ARGS);
	}
	env_unset(name);
	return (OK);
}
