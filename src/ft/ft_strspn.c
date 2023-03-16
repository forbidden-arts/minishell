/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:37:37 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/16 11:44:00 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft.h"

size_t	ft_strspn(const char *str, const char *charset)
{
	size_t	length;

	length = 0;
	while (str[length] && ft_strchr(charset, str[length]))
		length++;
	return (length);
}
