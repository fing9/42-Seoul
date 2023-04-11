/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_format_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 00:05:12 by seongmik          #+#    #+#             */
/*   Updated: 2023/04/11 11:54:47 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_format_xs(va_list *args, size_t *cnt)
{
	unsigned int	hex_num;
	size_t			len;

	hex_num = va_arg(*args, unsigned int);
	len = count_hex_uint_len(hex_num);
	ft_puthex_uint(hex_num);
	*cnt += len;
	return ;
}

void	printf_format_xl(va_list *args, size_t *cnt)
{
	unsigned int	hex_num;
	size_t			len;

	hex_num = va_arg(*args, unsigned int);
	len = count_hex_uint_len(hex_num);
	ft_puthex_uint_large(hex_num);
	*cnt += len;
	return ;
}

void	printf_format_percent(size_t *cnt)
{
	char	buf;

	buf = '%';
	write(1, &buf, 1);
	*cnt += 1;
	return ;
}
