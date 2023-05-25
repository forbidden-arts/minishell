/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:24:07 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/25 13:09:43 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"

static BOOL	cmp(void *item, void *m);

ssize_t	env_position(const t_env *env, t_env_match *match)
{
	return (vector_position((t_vector *)env, cmp, (void *)match));
}

static BOOL	cmp(void *item, void *m)
{
	t_env_match	*match;

	match = (t_env_match *)m;
	return (
		ft_strncmp(*(char **)item,
			match->name,
			match->name_length)
		== 0);
}

BOOL	is_name(const char *name, size_t limit)
{
	if (limit-- > 0 && *name)
	{
		if (!ft_isalpha(*name) && *name != '_')
			return (FALSE);
		name++;
	}
	while (limit-- > 0 && *name)
	{
		if (!ft_isalnum(*name) && *name != '_')
			return (FALSE);
		name++;
	}
	return (TRUE);
}
