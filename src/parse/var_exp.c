/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_exp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:20:03 by dpalmer           #+#    #+#             */
/*   Updated: 2023/04/27 14:49:38 by dpalmer          ###   ########.fr       */
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

BOOL	expand_variable(t_str *str, char *word, size_t *index)
{
	const char	*value;
	char		*tmp;

	if (word[++(*index)] == '?')
	{
		tmp = ft_itoa(g_shell.status);
		if (!str_push_ptr(str, tmp))
			return (FALSE);
		(*index) += 1;
		free(tmp);
	}
	else if (word[*index] == '_' || ft_isalpha(word[*index]))
	{
		tmp = ft_substr(word, *index, ft_strspn(&word[*index], AL_NUM));
		if (!tmp)
			return (FALSE);
		value = env_get(tmp);
		if (value && !str_push_ptr(str, value))
			return (FALSE);
		free(tmp);
		(*index) += ft_strspn(&word[*index], AL_NUM);
	}
	else if (!str_push(str, '$'))
		return (FALSE);
	return (TRUE);
}

BOOL	_expand_word(t_word *word, t_str *str)
{
	char	flags;
	size_t	index;

	flags = 0;
	index = 0;
	while ((*word)[index])
	{
		if ((*word)[index] == '$' && !(flags & S_QUOTE))
		{
			if (!expand_variable(str, *word, &index))
				return (FALSE);
		}
		else
		{
			if ((*word)[index] == '\'' && !(flags & D_QUOTE))
				flags ^= S_QUOTE;
			else if ((*word)[index] == '\"' && !(flags & S_QUOTE))
				flags ^= D_QUOTE;
			else if (!str_push(str, (*word)[index]))
				return (FALSE);
			index++;
		}
	}
	*word = str_as_ptr(str);
	return (TRUE);
}

BOOL	expand_word(t_word *word)
{
	t_str	*str;

	str = str_from_ptr("");
	if (!str)
		return (FALSE);
	if (!_expand_word(word, str))
	{
		str_free(str);
		return (FALSE);
	}
	return (TRUE);
}

BOOL	expand_tokens(t_vector *tokens)
{
	size_t	index;
	t_token	*token;

	index = 0;
	while (index < tokens->length)
	{
		token = vector_get(tokens, index);
		if (token->type == token_type_word)
		{
			if (!expand_word(&token->word))
				return (FALSE);
		}
		index++;
	}
	return (TRUE);
}
