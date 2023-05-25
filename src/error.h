/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:10:54 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/23 13:50:01 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/// Error defined by errno
# define EXIT_ERRNO 257
///	Syntax error
# define EXIT_SYNTAX 258
/// No command
# define EXIT_EMPTY 0b10000000000
/// Shell should exit
# define EXIT_FATAL 0b01000000000

/// Should print err
# define EXIT_PRINT_FLAG 0b100000000
# define EXIT_ERROR_MASK 0b111111111

# define EXIT_NOT_FOUND 126
# define EXIT_NO_ACCESS 127
# define EXIT_TERMSIG 128

void	print_error(int status);

#endif
