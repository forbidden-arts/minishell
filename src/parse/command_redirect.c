/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:14:04 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/22 13:09:20 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <readline/readline.h>
#include "libft.h"
#include "shell.h"
#include "util.h"
#include "command.h"

static int	heredoc(const char *delim);
static int	open_write(const char *path, BOOL append);

void	command_redirect_input(t_command *self, t_word word, BOOL is_heredoc)
{
	int	fd;

	if (is_heredoc)
		fd = heredoc(word);
	else
		fd = open(word, O_RDONLY);
	if (fd < 0)
	{
		perror("minishell");
		return ;
	}
	close_safe(&self->input_fd);
	self->input_fd = fd;
}

void	command_redirect_output(t_command *self, t_word word, BOOL append)
{
	int	fd;

	fd = open_write(word, append);
	if (fd < 0)
	{
		perror("minishell");
		return ;
	}
	close_safe(&self->output_fd);
	self->output_fd = fd;
}

static int	open_write(const char *path, BOOL append)
{
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	return (open(path, flags, 0644));
}

static int	heredoc(const char *delim)
{
	char	*line;
	int		io[2];

	if (pipe(io) < 0)
		return (-1);
	line = readline("> ");
	while (line && !g_shell.eof)
	{
		if (ft_strncmp(line, delim, ft_strlen(delim)) == 0)
			break ;
		write(io[1], line, ft_strlen(line));
		write(io[1], "\n", 1);
		free(line);
		line = readline("> ");
	}
	if (line)
		free(line);
	g_shell.eof = FALSE;
	close(io[1]);
	return (io[0]);
}
