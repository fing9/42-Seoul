/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_format_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 00:05:14 by seongmik          #+#    #+#             */
/*   Updated: 2023/04/11 15:28:52 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_format_c(va_list *args, size_t *cnt)
{
	int		c;

	c = (char)va_arg(*args, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	*cnt += 1;
	return (0);
}

int	printf_format_s(va_list *args, size_t *cnt)
{
	char	*str;
	size_t	len;

	str = va_arg(*args, char *);
	if (str == NULL)
	{
		if (write(1, "(null)", ft_strlen("(null)")) == -1)
			return (-1);
		*cnt += 6;
		return (0);
	}
	len = ft_strlen(str);
	if (write(1, str, len) == -1)
		return (-1);
	*cnt += len;
	return (0);
}

int	printf_format_p(va_list *args, size_t *cnt)
{
	void	*p;

	p = va_arg(*args, void *);
	if (write(1, "0x", 2) == -1)
		return (-1);
	*cnt += 2;
	if (sizeof(p) == (size_t)4)
	{
		if (ft_puthex_uint((unsigned long)p) == -1)
			return (-1);
		*cnt += count_hex_uint_len((unsigned long)p);
	}
	else
	{
		if (ft_puthex_ull((unsigned long long)p) == -1)
			return (-1);
		*cnt += count_hex_ull_len((unsigned long long)p);
	}
	return (0);
}

int	printf_format_d_i(va_list *args, size_t *cnt)
{
	int		dec_num;
	size_t	len;

	dec_num = va_arg(*args, int);
	len = count_dec_int_len(dec_num);
	if (ft_putint(dec_num) == -1)
		return (-1);
	*cnt += len;
	return (0);
}

int	printf_format_u(va_list *args, size_t *cnt)
{
	unsigned int	dec_num;
	size_t			len;

	dec_num = va_arg(*args, int);
	len = count_dec_uint_len(dec_num);
	if (ft_putuint(dec_num) == -1)
		return (-1);
	*cnt += len;
	return (0);
}
