/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 00:04:07 by seongmik          #+#    #+#             */
/*   Updated: 2023/04/11 11:30:42 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_dec_int_len(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr == -2147483648)
	{
		len += 11;
		return (len);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

size_t	count_hex_int_len(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr == -2147483648)
	{
		len += 9;
		return (len);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

size_t	count_dec_uint_len(unsigned int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

size_t	count_hex_uint_len(unsigned int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

size_t	count_hex_ull_len(unsigned long long nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}
