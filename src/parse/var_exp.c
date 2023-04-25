/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_exp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:20:03 by dpalmer           #+#    #+#             */
/*   Updated: 2023/04/25 14:42:56 by dpalmer          ###   ########.fr       */
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
	const char	*temp;
	size_t		name_len;

	temp = "$";
	name = NULL;
	name_len = 0;
	(*index) += 1;
	if (word[(*index)] == '?')
	{
		temp = ft_itoa(g_shell.status);
		name_len += 1;
	}
	else if (word[*index] == '_' || ft_isalpha(word[*index]))
	{
		name_len += ft_strspn(&word[*index], AL_NUM);
		name = ft_substr(word, *index, name_len);
		temp = env_get(name);
	}
	if (temp)
		str_push_ptr(self, temp);
	(*index) += name_len;
	if (name)
		free(name);
}

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

	if (!tokens)
		return (FALSE);
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
