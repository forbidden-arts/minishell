/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:00:43 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/11/03 17:06:41 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	len;

	len = 0;
	while (n-- > 0 && s[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*head;
	size_t	src_len;
	size_t	dst_len;
	size_t	max;

	dst_len = ft_strnlen(dst, dstsize);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	max = dstsize - dst_len - 1;
	head = &dst[dst_len];
	while (max-- > 0 && *src)
		*head++ = *src++;
	*head = '\0';
	return (src_len + dst_len);
}
