/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:47:56 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:09:38 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tostr.h"

char	*ft_utostr(unsigned int n, char *str, int len)
{
	while (n >= 10)
	{
		str[--len] = '0' + n % 10;
		n /= 10;
	}
	if (len > 0)
		str[--len] = '0' + n;
	while (len > 0)
		str[--len] = '0';
	return (str);
}

char	*ft_utoxstr(unsigned int n, char *str, int len)
{
	const char	*charset;

	charset = "0123456789abcdef";
	while (n >= 16)
	{
		str[--len] = charset[n % 16];
		n /= 16;
	}
	if (len > 0)
		str[--len] = charset[n % 16];
	while (len > 0)
		str[--len] = '0';
	return (str);
}

char	*ft_utouxstr(unsigned int n, char *str, int len)
{
	const char	*charset;

	charset = "0123456789ABCDEF";
	while (n >= 16)
	{
		str[--len] = charset[n % 16];
		n /= 16;
	}
	if (len > 0)
		str[--len] = charset[n % 16];
	while (len > 0)
		str[--len] = '0';
	return (str);
}

char	*ft_ptoxstr(uintptr_t n, char *str, int len)
{
	const char	*charset;

	charset = "0123456789abcdef";
	while (n >= 16)
	{
		str[--len] = charset[n % 16];
		n /= 16;
	}
	if (len > 0)
		str[--len] = charset[n % 16];
	while (len > 0)
		str[--len] = '0';
	return (str);
}
