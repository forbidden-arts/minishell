/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:34:30 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/10/29 20:47:29 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_strrev(char *s)
{
	size_t	len;
	size_t	i;
	size_t	max;
	char	tmp;

	i = 0;
	len = ft_strlen(s);
	max = len-- / 2;
	while (i < max)
	{
		tmp = s[len];
		s[len--] = s[i];
		s[i++] = tmp;
	}
	return (s);
}

static int	ft_itoa_countdigits(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/*
**	Allocates (with malloc(3)) and returns a string representing the integer
**	received as an argument. Negative numbers must be handled.
**
**	Return value:
**	- The string representing the integer.
**	- NULL if the allocation fails.
*/
char	*ft_itoa(int n)
{
	int		negative;
	char	*result;
	int		i;

	i = 0;
	negative = (n < 0);
	result = malloc(sizeof(char) * ft_itoa_countdigits(n) + 1 + negative);
	if (!result)
		return (NULL);
	if (n == 0)
		result[i++] = '0';
	if (negative)
	{
		result[i++] = (char)(-(n % 10) + 48);
		n = -(n / 10);
	}
	while (n > 0)
	{
		result[i++] = (char)(n % 10 + 48);
		n /= 10;
	}
	if (negative)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_itoa_strrev(result));
}
