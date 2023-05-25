/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:24:54 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/02 17:37:38 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_sectcount(char *s, char c)
{
	size_t	count;

	if (!c)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_split_sectcpy(char *s, char delim)
{
	size_t	len;
	char	c;
	char	*result;

	len = 0;
	c = s[len];
	while (c && c != delim)
		c = s[++len];
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result = ft_memcpy(result, s, sizeof(char) * len);
	result[len] = '\0';
	return (result);
}

static char	*ft_split_sectseek(char *s, char delim, int skip)
{
	if (skip)
	{
		while (*s && *s != delim)
			s++;
	}
	while (*s && *s == delim)
		s++;
	return (s);
}

static void	*ft_split_unwind(char **arr, size_t count)
{
	while (--count != (size_t)-1)
		free(arr[count]);
	free(arr);
	return (NULL);
}

/*
**	Allocates (with malloc(3)) and returns an array of strings obtained by
**	splitting ’s’ using the character ’c’ as a delimiter.  The array must end
**	with a NULL pointer.
**
**	Return value:
**	- The array of new strings resulting from the split.
**	- NULL if the allocation fails.
*/
char	**ft_split(char const *s, char c)
{
	int		count;
	char	**result;
	int		i;
	char	*head;

	if (!s)
		return (NULL);
	i = -1;
	count = ft_split_sectcount((char *)s, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	result[count] = NULL;
	if (!count)
		return (result);
	head = ft_split_sectseek((char *)s, c, 0);
	while (++i < count)
	{
		result[i] = ft_split_sectcpy(head, c);
		if (!result[i])
			return (ft_split_unwind(result, (size_t)i));
		head = ft_split_sectseek(head, c, 1);
	}
	return (result);
}
