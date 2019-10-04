/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:48:20 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/03/28 16:33:56 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const char	*ft_conversion(const char *str, t_flags *flags,
		size_t *count, va_list ap)
{
	if (*str == '%')
		ft_print_char('%', flags, count);
	else if (*str == 'c')
		ft_print_char((unsigned char)va_arg(ap, int), flags, count);
	else if (*str == 's')
		ft_print_str(va_arg(ap, char *), flags, count);
	else if (*str == 'd' || *str == 'i' || *str == 'D')
		ft_is_sdeci(flags, count, ap);
	else if (*str == 'u' || *str == 'U')
		ft_is_udeci(flags, count, ap);
	else if (*str == 'o' || *str == 'O')
		ft_is_oct(flags, count, ap);
	else if (*str == 'x' || *str == 'X')
		ft_is_hex(flags, count, ap, *str == 'x' ? 2 : 3);
	else if (*str == 'p')
		ft_print_pointer(va_arg(ap, void*), flags, count);
	else if (*str == 'f' || *str == 'F')
		ft_is_float(flags, count, ap);
	return (str + 1);
}
