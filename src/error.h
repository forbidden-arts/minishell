/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:10:54 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/16 08:21:17 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/// Error defined by errno
# define EXIT_ERRNO 256
///	Syntax error
# define EXIT_SYNTAX 257
/// Shell should exit
# define EXIT_FATAL 0b1000000000

# define EXIT_ERROR 125
# define EXIT_NOT_FOUND 126
# define EXIT_NO_ACCESS 127
# define EXIT_TERMSIG 128

void	print_error(int status);

#endif
