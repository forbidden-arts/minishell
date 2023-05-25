/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:12:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/10/26 13:18:33 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*result;

	size = ft_strlen(s1) + 1;
	result = malloc(sizeof(char) * size);
	if (result)
		ft_strlcpy(result, s1, size);
	return (result);
}
