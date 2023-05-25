/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:10:17 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/25 13:59:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "bool.h"

typedef struct s_line
{
	char	*inner;
	BOOL	is_eof;
	BOOL	is_empty;
}	t_line;

#endif
