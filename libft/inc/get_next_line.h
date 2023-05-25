/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:29:39 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/11/26 08:48:05 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "bool.h"
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

typedef struct s_gnl_readbuf
{
	char	*buf;
	char	*head;
	ssize_t	filled;
}	t_gnl_readbuf;

typedef struct s_gnl_outbuf
{
	char	*buf;
	size_t	size;
}	t_gnl_outbuf;

char			*get_next_line(int fd);
t_gnl_readbuf	*gnl_readbuf_from_fd(int fd);
void			gnl_readbuf_clear(t_gnl_readbuf **buf);
t_gnl_outbuf	*gnl_outbuf_new(void);
char			*gnl_outbuf_to_string(t_gnl_outbuf *buf);
BOOL			gnl_outbuf_append(
					t_gnl_outbuf **buf_out,
					t_gnl_readbuf **buf_read,
					size_t n);

#endif
