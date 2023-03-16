/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:34:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/03/16 13:12:35 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include "builtin.h"

void	builtin_pwd(char *arg_str)
{
	char	cwd[4096];

	(void)arg_str;
	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}
