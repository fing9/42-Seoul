/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_format_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 00:05:14 by seongmik          #+#    #+#             */
/*   Updated: 2023/04/11 11:56:49 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_format_c(va_list *args, size_t *cnt)
{
	int		c;

	c = (char)va_arg(*args, int);
	write(1, &c, 1);
	*cnt += 1;
	return ;
}

void	printf_format_s(va_list *args, size_t *cnt)
{
	char	*str;
	size_t	len;

	str = va_arg(*args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*cnt += 6;
		return ;
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	*cnt += len;
	return ;
}

void	printf_format_p(va_list *args, size_t *cnt)
{
	void	*p;

	p = va_arg(*args, void *);
	write(1, "0x", 2);
	*cnt += 2;
	if (sizeof(p) == (size_t)4)
	{
		ft_puthex_uint((unsigned long)p);
		*cnt += count_hex_uint_len((unsigned long)p);
	}
	else
	{
		ft_puthex_ull((unsigned long long)p);
		*cnt += count_hex_ull_len((unsigned long long)p);
	}
	return ;
}

void	printf_format_d_i(va_list *args, size_t *cnt)
{
	int		dec_num;
	size_t	len;

	dec_num = va_arg(*args, int);
	len = count_dec_int_len(dec_num);
	ft_putnbr_fd(dec_num, 1);
	*cnt += len;
	return ;
}

void	printf_format_u(va_list *args, size_t *cnt)
{
	unsigned int	dec_num;
	size_t			len;

	dec_num = va_arg(*args, int);
	len = count_dec_uint_len(dec_num);
	ft_putuint(dec_num);
	*cnt += len;
	return ;
}
