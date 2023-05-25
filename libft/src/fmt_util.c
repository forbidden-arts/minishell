/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:57:57 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:19:48 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

BOOL	fmt_leftalign(t_fmt *fmt)
{
	if (fmt->flags & FMT_LEFTALIGN)
		return (TRUE);
	return (FALSE);
}

BOOL	fmt_zeropad(t_fmt *fmt)
{
	if (fmt->flags & FMT_ZEROPAD)
		if (fmt->precision < 0)
			if (!fmt_leftalign(fmt))
				return (TRUE);
	return (FALSE);
}

BOOL	fmt_alternate(t_fmt *fmt)
{
	if (fmt->flags & FMT_ALTERNATE)
		return (TRUE);
	return (FALSE);
}

BOOL	fmt_forcesign(t_fmt *fmt)
{
	if (fmt->flags & FMT_FORCESIGN)
		return (TRUE);
	return (FALSE);
}

BOOL	fmt_signpad(t_fmt *fmt)
{
	if (fmt->flags & FMT_SIGNPAD)
		return (TRUE);
	return (FALSE);
}
