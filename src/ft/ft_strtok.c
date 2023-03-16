/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:57:02 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/16 11:57:42 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strtok(char *restrict str, const char *restrict delim)
{
	static char	*head;
	char		*result;

	if (str)
		head = str;
	result = head + ft_strspn(head, delim);
	head = result + ft_strcspn(head, delim);
	if (*head)
	{
		*head = '\0';
		head++;
	}
	if (*result)
		return (result);
	else
		return (NULL);
}
