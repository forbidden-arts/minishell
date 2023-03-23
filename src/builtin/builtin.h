/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:27:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/23 17:51:04 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "bool.h"

# define BUILTINS_LENGTH 5
///	Ok.
# define OK 0
///	Builtin was not found.
# define ERR_NOT_FOUND 1
///	Builtin was given an incorrect number of / invalid arguments.
# define ERR_INVALID_ARGS 2

typedef int	(*t_builtin_func)(char *);

typedef struct s_builtin
{
	char			*name;
	t_builtin_func	func;
}	t_builtin;

t_builtin_func	builtin_get(char *name);
int				builtin_exec(char *command_line);
int				builtin_echo(char *arg_str);
int				builtin_cd(char *arg_str);
int				builtin_pwd(char *arg_str);
int				builtin_export(char *arg_str);
int				builtin_unset(char *arg_str);
int				builtin_env(char *arg_str);
int				builtin_exit(char *arg_str);

#endif
