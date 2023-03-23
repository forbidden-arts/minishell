/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:43:40 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/20 19:38:42 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ft.h"
#include "env.h"
#include "shell.h"
#include "builtin.h"

void	builtin_export(char *arg_str)
{
	size_t	name_length;

	if (!arg_str)
		return ;
	name_length = ft_strcspn(arg_str, "=");
	if (name_length == 0 || !is_name(arg_str, name_length))
	{
		write(STDERR_FILENO, "minishell: export: `", 20);
		write(STDERR_FILENO, arg_str, name_length);
		write(STDERR_FILENO, "': not a valid identifier\n", 26);
		return ;
	}
	if (!arg_str[name_length])
		return ;
	arg_str[name_length] = '\0';
	env_set(arg_str, &arg_str[name_length + 1]);
}
