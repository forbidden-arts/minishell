/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:09 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/23 17:48:28 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ft.h"
#include "libft.h"
#include "env.h"
#include "shell.h"
#include "builtin.h"

int	builtin_unset(char *arg_str)
{
	if (!arg_str)
		return (ERR_INVALID_ARGS);
	if (!is_name(arg_str, (size_t)-1))
	{
		write(STDERR_FILENO, "minishell: unset: `", 20);
		write(STDERR_FILENO, arg_str, ft_strlen(arg_str));
		write(STDERR_FILENO, "': not a valid identifier\n", 26);
		return (ERR_INVALID_ARGS);
	}
	env_unset(arg_str);
	return (OK);
}
