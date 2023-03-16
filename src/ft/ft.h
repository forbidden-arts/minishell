/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:36:26 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/16 11:38:11 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stddef.h>
# include "bool.h"

BOOL	ft_isspace(char c);
size_t	ft_strspn(const char *str, const char *charset);
size_t	ft_strcspn(const char *str, const char *charset);

#endif
