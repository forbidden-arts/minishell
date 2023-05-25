/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:21:45 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/11/02 16:37:54 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim_start(char **str)
{
	char	c;
	int		negative;

	c = **str;
	while ((c >= '\t' && c <= '\r') || c == ' ')
		c = *(++(*str));
	negative = (c == '-');
	if (c == '+' || negative)
		c = *(++(*str));
	while (c == '0')
		c = *(++(*str));
	return (negative);
}

int	ft_atoi(const char *str)
{
	char	c;
	long	result;
	int		negative;

	result = 0;
	negative = ft_trim_start((char **)&str);
	c = *str++;
	while (ft_isdigit(c))
	{
		result = result * 10 - c + 48;
		if (negative && result >= 0)
			return ((int)(((unsigned long) - 2 / 2)) + 1);
		if (!negative && result - 1 >= 0)
			return ((int)((unsigned long) - 2 / 2));
		c = *str++;
	}
	if (negative)
		return ((int)result);
	return ((int)-result);
}
