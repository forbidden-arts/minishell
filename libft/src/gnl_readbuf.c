/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_readbuf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:35:50 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/11/26 08:52:00 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

t_gnl_readbuf	*gnl_readbuf_from_fd(int fd)
{
	t_gnl_readbuf	*buf;

	buf = malloc(sizeof(t_gnl_readbuf));
	if (!buf)
		return (NULL);
	buf->buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf->buf)
	{
		free(buf);
		return (NULL);
	}
	buf->head = buf->buf;
	buf->filled = read(fd, buf->buf, BUFFER_SIZE);
	if (buf->filled <= 0)
		gnl_readbuf_clear(&buf);
	return (buf);
}

void	gnl_readbuf_clear(t_gnl_readbuf **buf)
{
	if (*buf)
	{
		if ((*buf)->buf)
			free((*buf)->buf);
		free(*buf);
		*buf = NULL;
	}
}
