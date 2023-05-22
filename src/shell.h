/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:06:43 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/16 08:22:07 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "env.h"
# include <termios.h>

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
