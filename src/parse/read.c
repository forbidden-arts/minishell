/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:35:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/11 05:15:38 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

// TODO: Behavior of unknown metacharacters?

BOOL	read_word(const char *input, size_t *index, t_token *token)
{
	size_t	length;

	token->type = token_type_word;
	length = wordspan(&input[*index]);
	if (!length)
		return (FALSE);
	token->word = ft_substr(input, *index, length);
	if (!token->word)
		return (FALSE);
	(*index) += length;
	return (TRUE);
}

BOOL	read_operator(const char *input, size_t *index, t_token *token)
{
	token->type = token_type_operator;
	if (input[*index] == '|')
		token->operator = operator_pipe;
	else if (input[*index] == '<')
		token->operator = operator_infile;
	else if (input[*index] == '>')
		token->operator = operator_outfile_truncate;
	else
		return (FALSE);
	if (input[*index] == input[*index + 1])
	{
		token->operator += 1;
		(*index)++;
	}
	(*index)++;
	return (TRUE);
}
