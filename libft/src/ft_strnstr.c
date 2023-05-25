/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:02:07 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/11/03 14:37:47 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	while (i <= len)
	{
		if (!needle[j])
			return ((char *)&haystack[i - j]);
		if (!haystack[i])
			break ;
		if (haystack[i++] != needle[j++])
		{
			i = i - (j - 1);
			j = 0;
		}
	}
	return (NULL);
}
