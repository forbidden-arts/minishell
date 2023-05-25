/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:38:10 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:21:02 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "libft.h"

t_fmtblock	*fmt(const char *format, va_list ap)
{
	t_fmtblock	*list;
	t_fmtblock	**next;

	next = &list;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			*next = fmt_dynamic(&format, ap);
			if (!*next)
				return (NULL);
		}
		else
		{
			*next = fmt_static(format);
			format += (*next)->len;
			if (!*next)
				return (NULL);
		}
		next = (t_fmtblock **)&(*next)->next;
	}
	return (list);
}

t_fmtblock	*fmt_dynamic(const char **format, va_list ap)
{
	t_fmt		fmt;
	t_fmtblock	*result;

	fmt.flags = fmt_parse_flags(format);
	fmt.width = fmt_parse_width(format);
	if (fmt.width < 0)
	{
		fmt.width = -fmt.width;
		fmt.flags |= FMT_LEFTALIGN;
	}
	fmt.precision = fmt_parse_precision(format);
	result = fmt_arg(format, &fmt, ap);
	(*format)++;
	return (result);
}

t_fmtblock	*fmt_arg(const char **format, t_fmt *fmt, va_list ap)
{
	char	type;

	type = **format;
	if (type == 's')
		return (fmt_str(fmt, ap));
	if (type == 'i' || type == 'd')
		return (fmt_int(fmt, ap));
	if (type == 'u')
		return (fmt_uint(fmt, ap));
	if (type == 'p')
		return (fmt_ptr(fmt, ap));
	if (type == 'X')
		return (fmt_uhex(fmt, ap));
	if (type == 'x')
		return (fmt_lhex(fmt, ap));
	if (type == 'c')
		return (fmt_char(fmt, ap));
	if (type == '%')
		return (fmt_literal());
	return (NULL);
}

t_fmtblock	*fmt_static(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '%')
		len++;
	return (fmtblock_new((char *)str, len, FALSE));
}
