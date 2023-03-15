/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:34:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/15 14:41:42 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "builtin.h"

extern char	**environ;

void	builtin_env(char **argv)
{
	(void)argv;
	if (environ)
	{
		while (*environ)
		{
			printf("%s\n", *environ);
			environ++;
		}
	}
}
