/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:26:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:26:04 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FD_STDOUT 1

# include <stdarg.h>

int			ft_printf(const char *format, ...);
int			ft_vdprintf(int fd, const char *format, va_list ap);

#endif
