/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:10:20 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/15 16:59:43 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "builtin.h"
#include "libft.h"
#include "main.h"

int	main(void)
{
	char	**argv;

	while (1)
	{
		g_line.line = readline("> ");
		// TODO: g_line null b4 split?
		g_line.argv = ft_split(g_line.line, ' ');
		// TODO: Split err?
		exec_builtin(&g_line.argv[0], &g_line.argv[1]);
		free_line(&g_line);
	}
	return (0);
}

BOOL	exec_builtin(char *cmd, char **argv)
{
	if (ft_strncmp("exit", cmd, 5) == 0)
		builtin_exit(argv);
	else
		return (FALSE);
	return (TRUE);
}

void	free_line(t_line *line)
{
	// TODO:
}