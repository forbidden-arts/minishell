/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:32:26 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:20:10 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "libft.h"

static t_flags	fmt_flag(char c)
{
	if (c == '#')
		return (FMT_ALTERNATE);
	if (c == '-')
		return (FMT_LEFTALIGN);
	if (c == '+')
		return (FMT_FORCESIGN);
	if (c == '0')
		return (FMT_ZEROPAD);
	if (c == ' ')
		return (FMT_SIGNPAD);
	return (0);
}

t_flags	fmt_parse_flags(const char **format)
{
	t_flags	flags;
	t_flags	flag;

	flag = fmt_flag(**format);
	flags = 0;
	while (flag)
	{
		(*format)++;
		flags |= flag;
		flag = fmt_flag(**format);
	}
	return (flags);
}

int	fmt_parse_width(const char **format)
{
	int	width;

	width = ft_atoi(*format);
	while (ft_isdigit(**format) || **format == '-')
			(*format)++;
	return (width);
}

int	fmt_parse_precision(const char **format)
{
	int	precision;

	precision = -1;
	if (**format == '.')
	{
		(*format)++;
		precision = ft_atoi(*format);
		while (ft_isdigit(**format) || **format == '-')
			(*format)++;
	}
	return (precision);
}
