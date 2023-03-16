/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:34:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/16 13:12:24 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "builtin.h"

extern char	**environ;

void	builtin_env(char *arg_str)
{
	(void)arg_str;
	if (environ)
	{
		while (*environ)
		{
			printf("%s\n", *environ);
			environ++;
		}
	}
}
