/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:43:40 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/23 21:55:33 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ft.h"
#include "env.h"
#include "shell.h"
#include "builtin.h"

int	builtin_export(t_vector *argv)
{
	size_t	name_length;
	char	*arg;

	if (argv->length <= 1)
		return (ERR_INVALID_ARGS);
	arg = *(char **)vector_get(argv, 1);
	name_length = ft_strcspn(arg, "=");
	if (name_length == 0 || !is_name(arg, name_length))
	{
		write(STDERR_FILENO, "minishell: export: `", 20);
		write(STDERR_FILENO, arg, name_length);
		write(STDERR_FILENO, "': not a valid identifier\n", 26);
		return (ERR_INVALID_ARGS);
	}
	if (!arg[name_length])
		return (ERR_INVALID_ARGS);
	arg[name_length] = '\0';
	env_set(arg, &arg[name_length + 1]);
	return (OK);
}
