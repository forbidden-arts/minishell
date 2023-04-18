/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_exp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:20:03 by dpalmer           #+#    #+#             */
/*   Updated: 2023/04/18 17:00:02 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include "ft.h"
#include "parse.h"
#include "str.h"

	// check for $
	// check for single quote
	// check for double quote
	// mod vector in place
	// underscore, alphanum, cannot start with number

static void	var_parse(t_str *self, char *word, int *index)
{
	
}

static void	_expand(t_token *token)
{
	size_t	index;
	t_str	*temp;

	index = 0;
	while (token->word[index] != '\''
		&& token->word[index] != '\"'
		&& token->word[index] != '$'
		&& token->word[index])
		str_push(temp, token->word[index++]);
	if (token->word[index] == '$')
		var_expand(temp, token->word, &index);

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
			_expand(token);
		index++;
	}
	return (TRUE);
}
