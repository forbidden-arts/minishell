/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:55:08 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/11 03:49:05 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft.h"

char	*ft_strpbrk(const char *string, const char *charset)
{
	while (string)
	{
		if (ft_strchr(charset, *string))
			return ((char *)string);
		string++;
	}
	return (NULL);
}
