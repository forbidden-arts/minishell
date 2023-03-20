/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:24:07 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/20 19:32:48 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"

static BOOL	cmp(void *item, void *m);

ssize_t	env_position(t_vector *env_vector, t_env_match *match)
{
	return (vector_position(env_vector, cmp, (void *)match));
}

static BOOL	cmp(void *item, void *m)
{
	t_env_match	*match;

	match = (t_env_match *)m;
	return (ft_strncmp(*(char **)item, match->name, match->name_length) == 0);
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
