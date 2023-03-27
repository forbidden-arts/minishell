/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:46:12 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/23 17:01:30 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stddef.h>
# include "bool.h"
# include "vector.h"

typedef t_vector	t_env;

typedef struct s_env_match
{
	const char	*name;
	size_t		name_length;
}	t_env_match;

// ENV
BOOL		env_init(char **envp);
void		env_free(void);

// ENV_OPS
BOOL		env_set(const char *name, const char *value);
void		env_unset(const char *name);
const char	*env_get(const char *name);

// ENV_UTIL
ssize_t		env_position(t_vector *env_vector, t_env_match *match);
BOOL		is_name(const char *name, size_t limit);

#endif
