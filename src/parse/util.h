/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:55:58 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/12 18:53:06 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

void	close_safe(int *fd);
char	**argv_from_vector(t_vector **vector);
void	argv_free(char **argv);
char	**envp_from_env(const t_env *env);

#endif
