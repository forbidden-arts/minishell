/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 06:00:51 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/12 19:10:48 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

t_termios	*termios_init(void)
{
	t_termios	*termios_state;

	termios_state = malloc(sizeof(struct termios));
	if (!termios_state)
	{
		g_shell.status = ERR_ERRNO;
		return (NULL);
	}
	if (tcgetattr(STDIN_FILENO, termios_state))
	{
		free(termios_state);
		return (NULL);
	}
	return (termios_state);
}

void	termios_echoctl_disable(const t_termios *termios_state)
{
	t_termios	new_state;

	if (!termios_state)
		return ;
	if (termios_state->c_lflag & ECHOCTL)
	{
		new_state = *termios_state;
		new_state.c_lflag &= (~ECHOCTL);
		tcsetattr(STDIN_FILENO, TCSANOW, &new_state);
	}
}

void	termios_echoctl_reset(const t_termios *termios_state)
{
	if (!termios_state)
		return ;
	tcsetattr(STDIN_FILENO, TCSANOW, termios_state);
}
