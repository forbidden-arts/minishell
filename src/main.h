/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:10:17 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/12 19:23:01 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "parse.h"
# include "vector.h"

typedef struct s_parser
{
	char		*line;
	t_tokens	*tokens;
	t_vector	*commands;
}	t_parser;

#endif
