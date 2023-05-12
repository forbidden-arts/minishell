/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:36:26 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/05/11 02:04:53 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stddef.h>
# include "bool.h"

# define ERR_INVALID "The string did not consist solely of digit characters."
# define ERR_TOOSMALL "The result was smaller than the provided minimum value."
# define ERR_TOOLARGE "The result was larger than the provided maximum value."

BOOL		ft_isspace(char c);
size_t		ft_strspn(const char *str, const char *charset);
size_t		ft_strcspn(const char *str, const char *charset);
long long	ft_strtonum(
				const char *str,
				long long min,
				long long max,
				const char **errstr);
char		*ft_strtok(char *restrict str, const char *restrict delim);

///			Locate multiple characters in string.
///	
///			@details
///			Locates in the null-terminated string `string` the first occurrence
///			of any character in the string `charset` and returns a pointer to
///			this character. If no characters from `charset` occur anywhere in
///			`string`, NULL is returned.
///	
///			@param string Non-null string to search.
///			@param charset Non-null string defining the characters to search.
///	
///			@return Pointer to the first occurrence in `string` of any character
///			in `charset`, or NULL if no occurrences are found.
char		*ft_strpbrk(const char *string, const char *charset);

#endif
