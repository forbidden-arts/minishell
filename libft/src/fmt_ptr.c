/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:58:17 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:25:09 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "libft.h"
#include "tostr.h"

static t_fmtblock	*fmt_ptr_impl(t_fmt *fmt, uintptr_t n, int value_len)
{
	char	*str;
	int		total_len;
	int		offset;

	offset = 0;
	total_len = ft_imax(value_len + 2, fmt->width);
	str = malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (NULL);
	if (value_len < total_len)
	{
		ft_memset(str, ' ', total_len);
		if (!fmt_leftalign(fmt))
			offset = total_len - value_len - 2;
	}
	str[total_len] = '\0';
	ft_memcpy(&str[offset], "0x", 2);
	ft_ptoxstr(n, &str[offset + 2], value_len);
	return (fmtblock_new(str, total_len, TRUE));
}

t_fmtblock	*fmt_ptr(t_fmt *fmt, va_list ap)
{
	uintptr_t	n;
	int			value_len;

	n = (uintptr_t)va_arg(ap, void *);
	value_len = ft_pdigits(n);
	return (fmt_ptr_impl(fmt, n, value_len));
}
