/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:10:17 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/15 16:59:50 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "bool.h"

typedef struct s_line
{
	char	*line;
	char	**argv;
}	t_line;

t_line	g_line;

BOOL	exec_builtin(char *cmd, char **argv);
void	free_line(t_line *line);

#endif
