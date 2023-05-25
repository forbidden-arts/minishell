/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:25:59 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:04:05 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates (with malloc(3)) and returns a substring from the string ’s’.
**	The substring begins at index ’start’ and is of	maximum size ’len’.
**
**	Return values:
**	- The substring.
**	- NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	size;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	size = len + 1;
	if (s_len < len)
		size = s_len + 1;
	if (start > s_len)
		return (ft_strdup(""));
	result = malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s[start], size);
	return (result);
}
