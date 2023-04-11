/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:50:53 by seongmik          #+#    #+#             */
/*   Updated: 2023/04/11 11:54:57 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list *args, const char *str, size_t *idx, size_t *cnt)
{
	if (str[*idx + 1] == 'c')
		printf_format_c(args, cnt);
	else if (str[*idx + 1] == 's')
		printf_format_s(args, cnt);
	else if (str[*idx + 1] == 'p')
		printf_format_p(args, cnt);
	else if (str[*idx + 1] == 'd')
		printf_format_d_i(args, cnt);
	else if (str[*idx + 1] == 'i')
		printf_format_d_i(args, cnt);
	else if (str[*idx + 1] == 'u')
		printf_format_u(args, cnt);
	else if (str[*idx + 1] == 'x')
		printf_format_xs(args, cnt);
	else if (str[*idx + 1] == 'X')
		printf_format_xl(args, cnt);
	else if (str[*idx + 1] == '%')
		printf_format_percent(cnt);
	else
		return ;
	*idx += 1;
	return ;
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		i;
	size_t		cnt;

	va_start(args, str);
	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_format(&args, str, &i, &cnt);
		else
		{
			write(1, &str[i], 1);
			cnt++;
		}
		i++;
	}
	va_end(args);
	return (cnt);
}
