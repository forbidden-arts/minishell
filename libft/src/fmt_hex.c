/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:12:13 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:24:33 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "libft.h"
#include "tostr.h"

static t_fmtblock	*fmt_lhex_impl(t_fmt *fmt, unsigned int n, int value_len)
{
	char	*str;
	int		total_len;
	int		offset;
	int		prefix_len;

	offset = 0;
	prefix_len = 2 * (fmt_alternate(fmt) && n != 0);
	total_len = ft_imax(value_len + prefix_len, fmt->width);
	str = malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (NULL);
	if (value_len < total_len)
	{
		ft_memset(str, ' ', total_len);
		if (!fmt_leftalign(fmt))
			offset = total_len - value_len - prefix_len;
	}
	str[total_len] = '\0';
	if (prefix_len)
		ft_memcpy(&str[offset], "0x", prefix_len);
	ft_utoxstr(n, &str[offset + prefix_len], value_len);
	return (fmtblock_new(str, total_len, TRUE));
}

t_fmtblock	*fmt_lhex(t_fmt *fmt, va_list ap)
{
	unsigned int	n;
	int				value_len;

	n = va_arg(ap, unsigned int);
	if (fmt_zeropad(fmt))
		fmt->precision = fmt->width;
	value_len = ft_imax((int)ft_udigits_base(n, 16), fmt->precision);
	if (n == 0 && fmt->precision == 0)
		value_len = 0;
	return (fmt_lhex_impl(fmt, n, value_len));
}

static t_fmtblock	*fmt_uhex_impl(t_fmt *fmt, unsigned int n, int value_len)
{
	char	*str;
	int		total_len;
	int		offset;
	int		prefix_len;

	offset = 0;
	prefix_len = 2 * (fmt_alternate(fmt) && n != 0);
	total_len = ft_imax(value_len + prefix_len, fmt->width);
	str = malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (NULL);
	if (value_len < total_len)
	{
		ft_memset(str, ' ', total_len);
		if (!fmt_leftalign(fmt))
			offset = total_len - value_len - prefix_len;
	}
	str[total_len] = '\0';
	if (prefix_len)
		ft_memcpy(&str[offset], "0X", prefix_len);
	ft_utouxstr(n, &str[offset + prefix_len], value_len);
	return (fmtblock_new(str, total_len, TRUE));
}

t_fmtblock	*fmt_uhex(t_fmt *fmt, va_list ap)
{
	unsigned int	n;
	int				value_len;

	n = va_arg(ap, unsigned int);
	if (fmt_zeropad(fmt))
		fmt->precision = fmt->width;
	value_len = ft_imax((int)ft_udigits_base(n, 16), fmt->precision);
	if (n == 0 && fmt->precision == 0)
		value_len = 0;
	return (fmt_uhex_impl(fmt, n, value_len));
}
