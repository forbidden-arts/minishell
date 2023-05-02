/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:34:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/05/02 13:13:36 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "builtin.h"

int	builtin_pwd(t_vector *argv)
{
	char	cwd[PATH_BUFFER_SIZE];

	(void)argv;
	if (!getcwd(cwd, sizeof(cwd)))
	{
		perror("minishell: cd");
		return (EXIT_FAILURE);
	}
	printf("%s\n", cwd);
	return (OK);
}
