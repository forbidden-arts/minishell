/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:34:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:24:54 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "libft.h"
#include "tostr.h"

static const char	*prefix(t_fmt *fmt, int n)
{
	if (n < 0)
		return ("-");
	if (fmt_forcesign(fmt))
		return ("+");
	return (" ");
}

static t_fmtblock	*fmt_int_impl(
	t_fmt *fmt,
	int n,
	int value_len,
	int prefix_len )
{
	char	*str;
	int		total_len;
	int		offset;

	offset = 0;
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
		ft_memcpy(&str[offset], prefix(fmt, n), prefix_len);
	ft_utostr(ft_abs(n), &str[offset + prefix_len], value_len);
	return (fmtblock_new(str, total_len, TRUE));
}

t_fmtblock	*fmt_int(t_fmt *fmt, va_list ap)
{
	int	n;
	int	value_len;
	int	prefix_len;

	n = va_arg(ap, int);
	prefix_len = 1 * (n < 0 || fmt_forcesign(fmt) || fmt_signpad(fmt));
	if (fmt_zeropad(fmt))
		fmt->precision = fmt->width - prefix_len;
	value_len = ft_imax((int)ft_udigits_base(ft_abs(n), 10), fmt->precision);
	if (n == 0 && fmt->precision == 0)
		value_len = 0;
	return (fmt_int_impl(fmt, n, value_len, prefix_len));
}

static t_fmtblock	*fmt_uint_impl(t_fmt *fmt, unsigned int n, int value_len)
{
	char			*str;
	int				total_len;
	int				offset;

	offset = 0;
	total_len = ft_imax(value_len, fmt->width);
	str = malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (NULL);
	if (value_len < total_len)
	{
		ft_memset(str, ' ', total_len);
		if (!fmt_leftalign(fmt))
			offset = total_len - value_len;
	}
	str[total_len] = '\0';
	ft_utostr(n, &str[offset], value_len);
	return (fmtblock_new(str, total_len, TRUE));
}

t_fmtblock	*fmt_uint(t_fmt *fmt, va_list ap)
{
	unsigned int	n;
	int				value_len;

	n = va_arg(ap, unsigned int);
	if (fmt_zeropad(fmt))
		fmt->precision = fmt->width;
	value_len = ft_imax((int)ft_udigits_base(n, 10), fmt->precision);
	if (n == 0 && fmt->precision == 0)
		value_len = 0;
	return (fmt_uint_impl(fmt, n, value_len));
}
