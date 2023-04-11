/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_print_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:11:50 by seongmik          #+#    #+#             */
/*   Updated: 2023/04/11 15:37:40 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_uint(unsigned long nbr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr >= 16)
		if (ft_puthex_uint(nbr / 16) == -1)
			return (-1);
	if (write(1, &hex[nbr % 16], 1) == -1)
		return (-1);
	return (0);
}

int	ft_puthex_ull(unsigned long long nbr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr >= 16)
		if (ft_puthex_ull(nbr / 16) == -1)
			return (-1);
	if (write(1, &hex[nbr % 16], 1) == -1)
		return (-1);
	return (0);
}

int	ft_puthex_uint_large(unsigned long nbr)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (nbr >= 16)
		if (ft_puthex_uint_large(nbr / 16) == -1)
			return (-1);
	if (write(1, &hex[nbr % 16], 1) == -1)
		return (-1);
	return (0);
}
