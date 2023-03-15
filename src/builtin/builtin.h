/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:27:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/15 14:25:07 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

void	builtin_echo(char **argv);
void	builtin_cd(char **argv);
void	builtin_pwd(char **argv);
void	builtin_export(char **argv);
void	builtin_unset(char **argv);
void	builtin_env(char **argv);
void	builtin_exit(char **argv);

#endif
