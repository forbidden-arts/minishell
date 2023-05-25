/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:03:24 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/11/26 08:14:37 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_mempos(const void *s, unsigned char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (c == ((unsigned char *)s)[i])
			return ((ssize_t)i);
		i++;
	}
	return (-1);
}
