/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_outbuf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:37:42 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/11/26 08:51:21 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

t_gnl_outbuf	*gnl_outbuf_new(void)
{
	t_gnl_outbuf	*buf;

	buf = malloc(sizeof(t_gnl_outbuf));
	if (!buf)
		return (NULL);
	buf->size = 1;
	buf->buf = NULL;
	return (buf);
}

char	*gnl_outbuf_to_string(t_gnl_outbuf *buf)
{
	char	*output;

	output = NULL;
	if (buf->size > 1)
	{
		output = buf->buf;
		output[buf->size - 1] = '\0';
	}
	return (output);
}

BOOL	gnl_outbuf_append(
	t_gnl_outbuf **buf_out,
	t_gnl_readbuf **buf_read,
	size_t n)
{
	char	*new;
	size_t	size;

	size = (*buf_out)->size + n;
	new = malloc(sizeof(char) * size);
	if (!new)
		return (FALSE);
	if ((*buf_out)->size > 1)
		ft_memcpy(new, (*buf_out)->buf, (*buf_out)->size - 1);
	ft_memcpy(&new[(*buf_out)->size - 1], (*buf_read)->head, n);
	free((*buf_out)->buf);
	(*buf_out)->buf = new;
	(*buf_out)->size = size;
	(*buf_read)->filled -= n;
	if ((*buf_read)->filled <= 0)
		gnl_readbuf_clear(buf_read);
	else
		(*buf_read)->head += n;
	return (TRUE);
}
