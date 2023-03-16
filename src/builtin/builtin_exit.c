/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:27:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/16 13:12:17 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"
#include "builtin.h"

void	builtin_exit(char *arg_str)
{
	(void)arg_str;
	exit(EXIT_SUCCESS);
}
