/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:34:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/05/23 13:44:35 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "builtin.h"

int	builtin_pwd(t_vector *argv, t_env *env)
{
	char	cwd[PATH_BUFFER_SIZE];

	(void)env;
	(void)argv;
	if (!getcwd(cwd, sizeof(cwd)))
	{
		perror("minishell: cd");
		return (EXIT_FAILURE);
	}
	printf("%s\n", cwd);
	return (EXIT_SUCCESS);
}
