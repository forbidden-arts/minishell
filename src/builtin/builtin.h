/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:27:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/16 13:12:47 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

void	builtin_echo(char *arg_str);
void	builtin_cd(char *arg_str);
void	builtin_pwd(char *arg_str);
void	builtin_export(char *arg_str);
void	builtin_unset(char *arg_str);
void	builtin_env(char *arg_str);
void	builtin_exit(char *arg_str);

#endif
