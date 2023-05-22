/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:10:47 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/22 15:19:06 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "error.h"

void	print_error(int status)
{
	if ((status & EXIT_ERROR_MASK) == EXIT_ERRNO)
		perror("minishell");
	else if ((status & EXIT_ERROR_MASK) == EXIT_SYNTAX)
		write(STDERR_FILENO, "minishell: syntax error\n", 24);
}
