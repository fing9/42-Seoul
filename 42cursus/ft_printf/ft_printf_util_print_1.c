/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_print_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:59:35 by seongmik          #+#    #+#             */
/*   Updated: 2023/04/11 10:39:18 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint(unsigned int nbr)
{
	char	buf;

	if (nbr >= 10)
		ft_putuint(nbr / 10);
	buf = '0' + (nbr % 10);
	write(1, &buf, 1);
}
