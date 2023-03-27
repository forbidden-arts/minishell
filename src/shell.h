/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:06:43 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/23 17:02:08 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "env.h"

typedef struct s_shell
{
	char	*line;
	t_env	*env;
}	t_shell;

extern t_shell	g_shell;

void	shell_init(char **envp);
void	free_shell(void);

#endif
