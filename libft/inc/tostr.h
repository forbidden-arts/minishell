/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:06:22 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/12/04 13:09:11 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOSTR_H
# define TOSTR_H

/*
**	String conversions.
*/
// TODO: Revisit these..

# include <stdint.h>

/*
**	Writes the unsigned int argument into the given string, zero-padding if
**	`len` is larger than the number of digits written.
**
**	Returns `str`.
*/
char			*ft_utostr(unsigned int n, char *str, int len);

/*
**	Writes the unsigned int argument in lowercase hexadecimal format into the 
**	given string, zero-padding if `len` is larger than the number of digits
**	written.
**
**	Returns `str`.
*/
char			*ft_utoxstr(unsigned int n, char *str, int len);

/*
**	Writes the unsigned int argument in uppercase hexadecimal format into the 
**	given string, zero-padding if `len` is larger than the number of digits
**	written.
**
**	Returns `str`.
*/
char			*ft_utouxstr(unsigned int n, char *str, int len);

/*
**	Writes the uintpr_t argument in lowercase hexadecimal format into the 
**	given string, zero-padding if `len` is larger than the number of digits
**	written.
**
**	Returns `str`.
*/
char			*ft_ptoxstr(uintptr_t n, char *str, int len);

#endif