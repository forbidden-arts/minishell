/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:17:58 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:18:26 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

# include "bool.h"
# include "fmtblock.h"

# define FMT_LEFTALIGN		0b00001
# define FMT_ZEROPAD		0b00010
# define FMT_SIGNPAD		0b00100
# define FMT_FORCESIGN		0b01000
# define FMT_ALTERNATE		0b10000

typedef uint8_t	t_flags;

typedef struct s_fmt
{
	int		width;
	int		precision;
	t_flags	flags;
}	t_fmt;

t_fmtblock	*fmt(const char *format, va_list ap);
t_fmtblock	*fmt_static(const char *str);
t_fmtblock	*fmt_dynamic(const char **format, va_list ap);
t_fmtblock	*fmt_arg(const char **format, t_fmt *fmt, va_list ap);

t_flags		fmt_parse_flags(const char **format);
int			fmt_parse_width(const char **format);
int			fmt_parse_precision(const char **format);

t_fmtblock	*fmt_str(t_fmt *fmt, va_list ap);
t_fmtblock	*fmt_int(t_fmt *fmt, va_list ap);
t_fmtblock	*fmt_uint(t_fmt *fmt, va_list ap);
t_fmtblock	*fmt_ptr(t_fmt *fmt, va_list ap);
t_fmtblock	*fmt_uhex(t_fmt *fmt, va_list ap);
t_fmtblock	*fmt_lhex(t_fmt *fmt, va_list ap);
t_fmtblock	*fmt_char(t_fmt *fmt, va_list ap);
t_fmtblock	*fmt_literal(void);

BOOL		fmt_leftalign(t_fmt *fmt);
BOOL		fmt_zeropad(t_fmt *fmt);
BOOL		fmt_signpad(t_fmt *fmt);
BOOL		fmt_forcesign(t_fmt *fmt);
BOOL		fmt_alternate(t_fmt *fmt);

#endif
