/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:27:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/11 12:59:28 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "bool.h"
# include "shell.h"
# include "vector.h"

# define BUILTINS_LENGTH 7
///	Ok.
# define OK 0
///	Builtin was not found.

///	Builtin was given an incorrect number of / invalid arguments.
# define ERR_INVALID_ARGS 2
/// System errors
# define ERR_SYSTEM 3
/// Buffer for PWD
# define PATH_BUFFER_SIZE 4096

typedef int	(*t_builtin_func)(t_vector *argv, t_env *env);

typedef struct s_builtin
{
	char			*name;
	t_builtin_func	func;
}	t_builtin;

t_builtin_func	builtin_get(char *name);
int				builtin_exec(t_vector *argv, t_env *env);
int				builtin_echo(t_vector *argv, t_env *env);
int				builtin_cd(t_vector *argv, t_env *env);
int				builtin_pwd(t_vector *argv, t_env *env);
int				builtin_export(t_vector *argv, t_env *env);
int				builtin_unset(t_vector *argv, t_env *env);
int				builtin_env(t_vector *argv, t_env *env);
int				builtin_exit(t_vector *argv, t_env *env);

#endif
