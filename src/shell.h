/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:06:43 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/12 19:22:48 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "env.h"
# include <termios.h>

/// Minishell exited with an error
# define EXIT_ERROR 125
# define EXIT_NOT_FOUND 126
# define EXIT_NO_ACCESS 127
# define EXIT_TERMSIG 128

/// Status will cause shell to exit.
# define EXIT			0b0100000000000
/// Error should be printed with perror.
# define ERR_ERRNO		0b0010000000000
/// Syntax error.
# define ERR_SYNTAX		0b0000100000000
/// Invalid arguments for builtin.
# define ERR_ARGS		0b0001000000000
/// Command not found
# define ERR_NOT_FOUND	0b0001100000000
/// Child terminated with a signal
# define ERR_TERMSIG	0b1000000000000

# define SIGNAL_MASK 	0b0000011111111

/// Mask for custom errors
# define ERROR_MASK		0b0001100000000

typedef struct s_shell
{
	int				status;
	volatile BOOL	eof;
	volatile BOOL	is_waiting;
}	t_shell;

typedef struct s_state
{
	t_env			*env;
	struct termios	*termios_state;
}	t_state;

typedef struct termios	t_termios;
extern t_shell			g_shell;

void		handle_int(int signum);

BOOL		state_init(t_state *self, char **envp);
void		state_free(t_state *self);

t_termios	*termios_init(void);
void		termios_echoctl_disable(const t_termios *termios_state);
void		termios_echoctl_reset(const t_termios *termios_state);

#endif
