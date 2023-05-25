/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:16:20 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:16:29 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_udigits_base(unsigned int n, char base)
{
	size_t	digits;

	digits = 1;
	while (n >= (unsigned int)base)
	{
		n /= (unsigned int)base;
		digits++;
	}
	return (digits);
}

size_t	ft_pdigits(uintptr_t n)
{
	size_t	digits;

	digits = 1;
	while (n >= 16)
	{
		n /= 16;
		digits++;
	}
	return (digits);
}
