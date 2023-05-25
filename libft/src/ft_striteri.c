/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:51:11 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/10/29 00:40:18 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Applies the function ’f’ on each character of the string passed as argument,
**	passing its index as first argument.  Each character is passed by address
**	to ’f’ to be modified if necessary.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
