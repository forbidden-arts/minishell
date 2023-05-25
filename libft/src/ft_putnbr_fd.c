/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:19:12 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/10/29 20:48:26 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		return (ft_putchar_fd((char)(n % 10 + 48), fd));
	}
	if (n >= 0)
		return (ft_putchar_fd((char)(n + 48), fd));
	ft_putchar_fd('-', fd);
	if (n - 1 < 0)
		return (ft_putnbr_fd(-n, fd));
	ft_putnbr_fd(-(n / 10), fd);
	ft_putnbr_fd(-(n % 10), fd);
}
