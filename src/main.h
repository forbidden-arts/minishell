/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:10:17 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/16 13:13:06 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "bool.h"

typedef struct s_shell
{
	char	*line;
}	t_shell;

t_shell	g_shell;

BOOL	exec_builtin(char *command_line);
void	free_shell(void);

#endif
