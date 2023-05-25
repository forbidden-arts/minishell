/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:34:00 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:19:55 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "libft.h"

static t_fmtblock	*fmt_str_dyn(
	t_fmt *fmt,
	const char *s,
	size_t len
)
{
	size_t	size;
	char	*str;
	size_t	offset;

	offset = 0;
	size = fmt->width + 1;
	str = malloc(size);
	if (!str)
		return (NULL);
	ft_memset(str, ' ', fmt->width);
	if (!fmt_leftalign(fmt))
		offset = fmt->width - len;
	ft_memcpy(&str[offset], s, len);
	str[fmt->width] = '\0';
	return (fmtblock_new(str, fmt->width, TRUE));
}

static char	*ft_uctoa(unsigned char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	ft_bzero(str, 2);
	str[0] = c;
	return (str);
}

t_fmtblock	*fmt_char(t_fmt *fmt, va_list ap)
{
	unsigned char	c;
	char			*str;

	c = (unsigned char)va_arg(ap, int);
	if (fmt->width > 1)
		return (fmt_str_dyn(fmt, (const char *)&c, 1));
	str = ft_uctoa(c);
	if (!str)
		return (NULL);
	return (fmtblock_new(str, 1, TRUE));
}

t_fmtblock	*fmt_str(t_fmt *fmt, va_list ap)
{
	const char	*str;
	int			len;

	str = va_arg(ap, const char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (fmt->precision >= 0 && fmt->precision < len)
		len = fmt->precision;
	if (fmt->width > len)
		return (fmt_str_dyn(fmt, str, len));
	return (fmtblock_new((char *)str, len, FALSE));
}

t_fmtblock	*fmt_literal(void)
{
	return (fmtblock_new("%", 1, FALSE));
}
