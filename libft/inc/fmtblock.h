/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmtblock.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:11:41 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:12:13 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMTBLOCK_H
# define FMTBLOCK_H

# include <stdlib.h>
# include "bool.h"

typedef struct s_fmtblock
{
	char	*p;
	BOOL	dynamic;
	size_t	len;
	void	*next;
}	t_fmtblock;

t_fmtblock	*fmtblock_new(char *p, size_t len, BOOL dynamic);
int			fmtblock_write_all(t_fmtblock *list, int fd);
void		*fmtblock_free_all(t_fmtblock *list);

#endif
