/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:38:35 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/16 11:41:31 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft.h"

size_t	ft_strcspn(const char *str, const char *charset)
{
	size_t	length;

	length = 0;
	while (str[length] && !ft_strchr(charset, str[length]))
		length++;
	return (length);
}
