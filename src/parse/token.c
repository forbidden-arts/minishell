/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:14:36 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/22 15:22:40 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "libft.h"
#include "error.h"
#include "parse.h"

static int	_tokenize(const char *line, t_vector *tokens);

int	tokenize(const char *line, t_tokens **tokens)
{
	int				status;

	*tokens = vector_with_capacity(1, sizeof(t_token));
	if (!*tokens)
		return (EXIT_ERRNO);
	status = _tokenize(line, *tokens);
	if (status != EXIT_SUCCESS)
	{
		tokens_free(*tokens);
		*tokens = NULL;
		return (status);
	}
	return (EXIT_SUCCESS);
}

static int	_tokenize(const char *line, t_vector *tokens)
{
	size_t	index;
	t_token	token;
	int		status;

	index = 0;
	while (TRUE)
	{
		index += ft_strspn(&line[index], CHARSET_DELIM);
		if (!line[index])
			break ;
		if (ft_strchr(CHARSET_META, line[index]))
			status = read_operator(line, &index, &token);
		else
			status = read_word(line, &index, &token);
		if (status == EXIT_SUCCESS && !vector_push(tokens, &token))
			status = EXIT_ERRNO;
		if (status != EXIT_SUCCESS)
			return (status);
	}
	return (EXIT_SUCCESS);
}

void	tokens_free(t_tokens *tokens)
{
	size_t	index;
	t_token	*token;

	index = 0;
	while (index < tokens->length)
	{
		token = vector_get(tokens, index);
		if (token->type == token_type_word)
			free(token->word);
		index++;
	}
	vector_free(tokens);
}

t_token	token_from_word(t_word word)
{
	t_token	token;

	token.type = token_type_word;
	token.word = word;
	return (token);
}

t_token	token_from_operator(t_operator operator)
{
	t_token	token;

	token.type = token_type_operator;
	token.operator = operator;
	return (token);
}
