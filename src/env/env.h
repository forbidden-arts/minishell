/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:46:12 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/23 14:38:14 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stddef.h>
# include "bool.h"
# include "vector.h"

typedef t_vector	t_env;

typedef t_vector	t_path;

typedef struct s_env_match
{
	const char	*name;
	size_t		name_length;
}	t_env_match;

// ENV
t_env		*env_init(char **envp);
void		env_free(t_env **env);
t_env		*env_clone(const t_env *self);

// ENV_OPS
BOOL		env_set(t_env *env, const char *name, const char *value);
void		env_unset(t_env *env, const char *name);
const char	*env_get(const t_env *env, const char *name);

// ENV_UTIL
ssize_t		env_position(const t_env *env, t_env_match *match);
BOOL		is_name(const char *name, size_t limit);

// PATH
t_path		*path_from_env(const t_env *env);
void		path_free(t_path *self);
char		*path_which(t_path *self, const char *name);

#endif
