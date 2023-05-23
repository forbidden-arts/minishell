/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:09:05 by dpalmer           #+#    #+#             */
/*   Updated: 2023/05/23 14:22:35 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "builtin.h"

int	builtin_echo(t_vector *argv, t_env *env)
{
	size_t	index;
	BOOL	n_flag;

	(void)env;
	index = 1;
	n_flag = FALSE;
	if (argv->length < 2)
	{
		printf("\n");
		return (EXIT_SUCCESS);
	}
	if (!ft_strncmp(*(char **)vector_get(argv, 1), "-n", 2))
	{
		n_flag = TRUE;
		index++;
	}
	if (index < argv->length)
		printf("%s", *(char **)vector_get(argv, index++));
	while (index < argv->length)
		printf(" %s", *(char **)vector_get(argv, index++));
	if (!n_flag)
		printf("\n");
	return (EXIT_SUCCESS);
}
