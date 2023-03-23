/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:09 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/23 22:03:42 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ft.h"
#include "libft.h"
#include "env.h"
#include "shell.h"
#include "builtin.h"

int	builtin_unset(t_vector *argv)
{
	char	*arg;

	if (argv->length <= 1)
		return (ERR_INVALID_ARGS);
	arg = *(char **)vector_get(argv, 1);
	if (!is_name(arg, (size_t)-1))
	{
		write(STDERR_FILENO, "minishell: unset: `", 20);
		write(STDERR_FILENO, arg, ft_strlen(arg));
		write(STDERR_FILENO, "': not a valid identifier\n", 26);
		return (ERR_INVALID_ARGS);
	}
	env_unset(arg);
	return (OK);
}
