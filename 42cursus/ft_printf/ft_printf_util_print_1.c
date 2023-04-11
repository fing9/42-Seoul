/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_print_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:59:35 by seongmik          #+#    #+#             */
/*   Updated: 2023/04/11 15:35:29 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int nbr)
{
	char	buf;

	if (nbr == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (0);
	}
	if (nbr < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nbr *= -1;
	}
	if (nbr >= 10)
		if (ft_putint(nbr / 10) == -1)
			return (-1);
	buf = '0' + (nbr % 10);
	if (write(1, &buf, 1) == -1)
		return (-1);
	return (0);
}

int	ft_putuint(unsigned int nbr)
{
	char	buf;

	if (nbr >= 10)
		if (ft_putuint(nbr / 10) == -1)
			return (-1);
	buf = '0' + (nbr % 10);
	if (write(1, &buf, 1) == -1)
		return (-1);
	return (0);
}
