/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:00:41 by seongmik          #+#    #+#             */
/*   Updated: 2023/04/11 11:54:51 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_format(va_list *args, const char *str, size_t *idx, size_t *cnt);
size_t	count_dec_int_len(int nbr);
size_t	count_hex_int_len(int nbr);
size_t	count_dec_uint_len(unsigned int nbr);
size_t	count_hex_uint_len(unsigned int nbr);
size_t	count_hex_ull_len(unsigned long long nbr);
void	printf_format_c(va_list *args, size_t *cnt);
void	printf_format_s(va_list *args, size_t *cnt);
void	printf_format_p(va_list *args, size_t *cnt);
void	printf_format_d_i(va_list *args, size_t *cnt);
void	printf_format_u(va_list *args, size_t *cnt);
void	printf_format_xs(va_list *args, size_t *cnt);
void	printf_format_xl(va_list *args, size_t *cnt);
void	printf_format_percent(size_t *cnt);
void	ft_putuint(unsigned int nbr);
void	ft_puthex_uint(unsigned long nbr);
void	ft_puthex_ull(unsigned long long nbr);
void	ft_puthex_uint_large(unsigned long nbr);

#endif