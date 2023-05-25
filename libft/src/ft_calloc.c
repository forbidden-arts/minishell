/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:37:13 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/11/04 15:22:26 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	size_full;

	if (!count || !size)
		return (ft_calloc(1, 1));
	size_full = count * size;
	if (size_full / size != count)
		return (NULL);
	result = malloc(size_full);
	if (result)
		ft_bzero(result, size_full);
	return (result);
}
