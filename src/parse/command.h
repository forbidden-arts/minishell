/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 03:47:22 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/25 13:25:50 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "vector.h"
# include "env.h"
# include "parse.h"
# include "builtin.h"

typedef struct s_command_name
{
	char	*value;
	BOOL	is_path;
}	t_command_name;

typedef struct s_command
{
	int				input_fd;
	int				output_fd;
	t_vector		*args;
	pid_t			pid;
	int				status;
	t_builtin_func	builtin;
	t_command_name	name;
}	t_command;

BOOL		command_new(t_command *self);
void		command_free(t_command *self);

int			commands_from_tokens(t_tokens *tokens, t_vector **commands);
void		commands_free(t_vector *self);

int			commands_init(t_tokens *tokens, t_vector *commands);
void		commands_exec(t_vector *commands, t_env *env);
void		command_run_builtin(t_command *self, t_env *env);
void		command_redirect(t_command *self);
BOOL		command_resolve(t_command *self, const t_env *env);

void		command_wait(t_command *self);

///			Waits on all the commands to finish executing, and returns the
///			status of the final command.
int			commands_status(t_vector *commands);

// Redirect stufs
void		command_redirect_input(
				t_command *self,
				t_word word,
				BOOL is_heredoc);
void		command_redirect_output(t_command *self, t_word word, BOOL append);

#endif
