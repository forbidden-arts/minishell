/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_exp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:20:03 by dpalmer           #+#    #+#             */
/*   Updated: 2023/04/25 19:19:39 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include "ft.h"
#include "env.h"
#include "shell.h"
#include "parse.h"
#include "str.h"

#define AL_NUM "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define D_QUOTE 0b01
#define S_QUOTE 0b10

static void	var_expand(t_str *self, char *word, size_t *index)
{
	char		*name;
	size_t		name_len;

	if (word[++(*index)] == '?')
	{
		if (str_push_ptr(self, (const char *)ft_itoa(g_shell.status)))
			(*index) += 1;
	}
	else if (word[*index] == '_' || ft_isalpha(word[*index]))
	{
		name_len = ft_strspn(&word[*index], AL_NUM);
		name = ft_substr(word, *index, name_len);
		if (env_get(name))
			str_push_ptr(self, env_get(name));
		free(name);
		(*index) += name_len;
	}
	else
		str_push(self, '$');
}

// static char	flags_check(char c, char flags, size_t *index)
// {
// 	if (c == '\'' && !(flags & D_QUOTE))
// 	{
// 		flags ^= S_QUOTE;
// 		(*index) += 1;
// 	}
// 	else if (c == '\"' && !(flags & S_QUOTE))
// 	{
// 		flags ^= D_QUOTE;
// 		(*index) += 1;
// 	}
// 	return (flags);
// }

static void	_expand(t_word *word)
{
	char	flags;
	size_t	index;
	t_str	*temp;

	flags = 0;
	index = 0;
	temp = str_from_ptr("");
	while ((*word)[index])
	{
		if ((*word)[index] == '$' && !(flags & S_QUOTE))
			var_expand(temp, *word, &index);
		else if ((*word)[index] == '\'' && !(flags & D_QUOTE))
		{
			flags ^= S_QUOTE;
			index++;
		}
		else if ((*word)[index] == '\"' && !(flags & S_QUOTE))
		{
			flags ^= D_QUOTE;
			index++;
		}
		else
			str_push(temp, (*word)[index++]);
	}
	*word = str_as_ptr(temp);
}

BOOL	expand(t_vector *tokens)
{
	size_t	index;
	t_token	*token;

	index = 0;
	while (index < tokens->length)
	{
		token = vector_get(tokens, index);
		if (token->type == token_type_word)
			_expand(&token->word);
		index++;
	}
	return (TRUE);
}
