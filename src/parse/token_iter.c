/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:07:47 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/01 05:58:46 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "parse.h"

void	tokens_iter(t_tokens_iter *iterator, t_tokens *tokens)
{
	iterator->tokens = tokens;
	iterator->index = 0;
}

t_token	*tokens_next(t_tokens_iter *iterator)
{
	if (iterator->index < iterator->tokens->length)
		return (vector_get(iterator->tokens, iterator->index++));
	return (NULL);
}
