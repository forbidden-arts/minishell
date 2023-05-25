/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:39:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/11/26 08:51:10 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

static char	*get_next_line_impl(
	int fd,
	t_gnl_readbuf **buf_read,
	t_gnl_outbuf **buf_out
)
{
	ssize_t	nlpos;

	while (TRUE)
	{
		if (!*buf_read)
			*buf_read = gnl_readbuf_from_fd(fd);
		if (!*buf_read)
			return (gnl_outbuf_to_string(*buf_out));
		nlpos = ft_mempos((*buf_read)->head, '\n', (*buf_read)->filled);
		if (nlpos >= 0)
		{
			if (gnl_outbuf_append(buf_out, buf_read, nlpos + 1))
				return (gnl_outbuf_to_string(*buf_out));
			return (NULL);
		}
		if (!gnl_outbuf_append(buf_out, buf_read, (*buf_read)->filled))
			return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_readbuf	*buf_read;
	t_gnl_outbuf			*buf_out;
	char					*output;

	buf_out = gnl_outbuf_new();
	output = get_next_line_impl(fd, &buf_read, &buf_out);
	if (!output)
		gnl_readbuf_clear(&buf_read);
	if (buf_out)
	{
		if (!output && buf_out->buf)
			free(buf_out->buf);
		free(buf_out);
	}
	return (output);
}
