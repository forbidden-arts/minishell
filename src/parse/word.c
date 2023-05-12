/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:51:36 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/01 05:55:08 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "parse.h"

size_t	wordspan(const char *input)
{
	size_t	index;

	index = 0;
	while (input[index])
	{
		index += ft_strcspn(&input[index], CHARSET_QUOT_DELIM_META);
		if (input[index] == '\'')
		{
			index++;
			index += ft_strcspn(&input[index], "\'");
			if (input[index++] != '\'')
				return (0);
		}
		else if (input[index] == '\"')
		{
			index++;
			index += ft_strcspn(&input[index], "\"");
			if (input[index++] != '\"')
				return (0);
		}
		else
			return (index);
	}
	return (index);
}
