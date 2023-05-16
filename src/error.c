/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:10:47 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/16 02:58:15 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "error.h"

void	print_error(int status)
{
	if (status == 256)
		perror("minishell");
	else if (status == 257)
		write(STDERR_FILENO, "minishell: syntax error\n", 24);
}
