/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:50:53 by seongmik          #+#    #+#             */
/*   Updated: 2023/04/11 12:10:35 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list *args, const char *str, size_t *idx, size_t *cnt)
{
	int	ret;

	if (str[*idx + 1] == 'c')
		ret = printf_format_c(args, cnt);
	else if (str[*idx + 1] == 's')
		ret = printf_format_s(args, cnt);
	else if (str[*idx + 1] == 'p')
		ret = printf_format_p(args, cnt);
	else if (str[*idx + 1] == 'd')
		ret = printf_format_d_i(args, cnt);
	else if (str[*idx + 1] == 'i')
		ret = printf_format_d_i(args, cnt);
	else if (str[*idx + 1] == 'u')
		ret = printf_format_u(args, cnt);
	else if (str[*idx + 1] == 'x')
		ret = printf_format_xs(args, cnt);
	else if (str[*idx + 1] == 'X')
		ret = printf_format_xl(args, cnt);
	else if (str[*idx + 1] == '%')
		ret = printf_format_percent(cnt);
	else
		return (0);
	*idx += 1;
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		i;
	size_t		cnt;
	int			ret;

	va_start(args, str);
	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ret = ft_format(&args, str, &i, &cnt);
		else
		{
			ret = write(1, &str[i], 1);
			cnt++;
		}
		if (ret == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (cnt);
}
