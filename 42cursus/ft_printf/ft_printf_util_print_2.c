/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_print_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:11:50 by seongmik          #+#    #+#             */
/*   Updated: 2023/04/11 11:56:30 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_uint(unsigned long nbr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_puthex_uint(nbr / 16);
	}
	write(1, &hex[nbr % 16], 1);
}

void	ft_puthex_ull(unsigned long long nbr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_puthex_ull(nbr / 16);
	}
	write(1, &hex[nbr % 16], 1);
}

void	ft_puthex_uint_large(unsigned long nbr)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_puthex_uint_large(nbr / 16);
	}
	write(1, &hex[nbr % 16], 1);
}
