/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:40:56 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/04/05 14:46:33 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stddef.h>
# include "bool.h"

typedef struct s_str
{
	char	*buffer;
	size_t	length;
	size_t	capacity;
}	t_str;

t_str	*str_from_ptr(const char *str);
char	*str_as_ptr(t_str *self);
BOOL	str_push(t_str *self, char c);
BOOL	str_push_ptr(t_str *self, const char *str);
void	str_free(t_str *self);
BOOL	str_reserve(t_str *self, size_t additional_capacity);
BOOL	str_grow(t_str *self);

#endif
