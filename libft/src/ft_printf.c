/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:45:51 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:26:20 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "fmt.h"
#include <unistd.h>

int	ft_printf(const char *format, ...)
{	
	va_list	ap;
	int		len;

	if (!format)
		return (-1);
	va_start(ap, format);
	len = ft_vdprintf(FD_STDOUT, format, ap);
	va_end(ap);
	return (len);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int			len;
	t_fmtblock	*list;

	list = fmt(format, ap);
	if (!list)
		return (-1);
	len = fmtblock_write_all(list, fd);
	return (len);
}
