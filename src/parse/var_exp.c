/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_exp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:20:03 by dpalmer           #+#    #+#             */
/*   Updated: 2023/05/02 15:36:57 by tjaasalo         ###   ########.fr       */
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

// TODO: Filenames array needs internal free

BOOL	expand_variable(t_str *str, t_word word, size_t *index)
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
	ssize_t	index;

	flags = 0;
	index = -1;
	while ((*word)[++index])
	{
		if ((*word)[index] == '$' && !(flags & S_QUOTE))
		{
			if (!expand_variable(str, *word, (size_t *)&index))
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
		}
	}
	free(*word);
	*word = str_as_ptr(str);
	return (TRUE);
}

static BOOL	_expand_word_unquoted(t_word *word, t_str *str)
{
	size_t	index;

	index = 0;
	while ((*word)[index])
	{
		if ((*word)[index] == '$')
		{
			if (!expand_variable(str, *word, &index))
				return (FALSE);
		}
		index++;
	}
	return (TRUE);
}

BOOL	expand_word(t_word *word, BOOL ignore_quotes)
{
	t_str	*str;
	BOOL	ok;

	str = str_from_ptr("");
	if (!str)
		return (FALSE);
	if (ignore_quotes)
		ok = _expand_word_unquoted(word, str);
	else
		ok = _expand_word(word, str);
	if (ok)
		return (TRUE);
	str_free(str);
	return (FALSE);
}

BOOL	expand_filenames(t_word word, t_vector *result)
{
	size_t		index;
	t_vector	*filenames;
	char		*filename;

	if (!expand_word(&word, TRUE))
		return (FALSE);
	filenames = filename_expansion(word);
	if (!filenames)
		return (FALSE);
	index = 0;
	while (index < filenames->length)
	{
		filename = *(char **)vector_get(filenames, index);
		if (!vector_push(result, &filename))
		{
			vector_free(filenames);
			return (FALSE);
		}
		index++;
	}
	vector_free(filenames);
	return (TRUE);
}

BOOL	should_expand_filename(t_word word)
{
	size_t	index;
	BOOL	has_wildcard;

	index = 0;
	has_wildcard = FALSE;
	while (word[index])
	{
		if (word[index] == '\'' || word[index] == '\"')
			return (FALSE);
		if (word[index] == '*')
			has_wildcard = TRUE;
		index++;
	}
	return (has_wildcard);
}

static BOOL	_expand_tokens(t_vector *tokens, t_vector *result)
{
	size_t		index;
	t_token		*token;

	index = 0;
	while (index < tokens->length)
	{
		token = vector_get(tokens, index++);
		if (token->type == token_type_word)
		{
			if (should_expand_filename(token->word))
			{
				if (!expand_filenames(token->word, result))
					return (FALSE);
			}
			else if (!expand_word(&token->word, FALSE))
				return (FALSE);
			else if (!vector_push(result, &token))
				return (FALSE);
		}
		else if (!vector_push(result, &token))
			return (FALSE);
	}
	return (TRUE);
}

t_vector	*expand_tokens(t_vector *tokens)
{
	t_vector	*result;

	result = vector_with_capacity(tokens->length, sizeof(t_token));
	if (!result)
		return (NULL);
	if (!_expand_tokens(tokens, result))
	{
		tokens_free(result);
		return (NULL);
	}
	return (result);
}
