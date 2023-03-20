/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:27:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/19 09:12:55 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "bool.h"

# define BUILTINS_LENGTH 3

typedef void	(*t_builtin_func)(char *);

typedef struct s_builtin
{
	char			*name;
	t_builtin_func	func;
}	t_builtin;

t_builtin_func	builtin_get(char *name);
BOOL			builtin_exec(char *command_line);
void			builtin_echo(char *arg_str);
void			builtin_cd(char *arg_str);
void			builtin_pwd(char *arg_str);
void			builtin_export(char *arg_str);
void			builtin_unset(char *arg_str);
void			builtin_env(char *arg_str);
void			builtin_exit(char *arg_str);

#endif
