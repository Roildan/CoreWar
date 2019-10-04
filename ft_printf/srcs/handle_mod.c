/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:30:07 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/03/28 16:33:52 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "printf.h"

void	ft_is_sdeci(t_flags *flags, size_t *count, va_list ap)
{
	if (flags->mod <= 2)
		ft_print_sdeci((long)va_arg(ap, int), flags, count);
	else if (flags->mod == 3)
		ft_print_sdeci((long)va_arg(ap, long), flags, count);
	else
		ft_print_sdeci((long)va_arg(ap, long long), flags, count);
}

void	ft_is_udeci(t_flags *flags, size_t *count, va_list ap)
{
	if (flags->mod <= 2)
		ft_print_udeci((unsigned long)va_arg(ap, unsigned int), flags, count);
	else if (flags->mod == 3)
		ft_print_udeci((unsigned long)va_arg(ap, unsigned long), flags, count);
	else
		ft_print_udeci((unsigned long)va_arg(ap, unsigned long long),
				flags, count);
}

void	ft_is_oct(t_flags *flags, size_t *count, va_list ap)
{
	if (flags->mod <= 2)
		ft_print_oct((unsigned long)va_arg(ap, unsigned int), flags, count);
	else if (flags->mod == 3)
		ft_print_oct((unsigned long)va_arg(ap, unsigned long), flags, count);
	else
		ft_print_oct((unsigned long)va_arg(ap, unsigned long long),
				flags, count);
}

void	ft_is_hex(t_flags *flags, size_t *count, va_list ap, int i)
{
	if (flags->mod <= 2)
		ft_print_hex((unsigned long)va_arg(ap, unsigned int), flags, count, i);
	else if (flags->mod == 3)
		ft_print_hex((unsigned long)va_arg(ap, unsigned long), flags, count, i);
	else
		ft_print_hex((unsigned long)va_arg(ap, unsigned long long),
				flags, count, i);
}

void	ft_is_float(t_flags *flags, size_t *count, va_list ap)
{
	long double	ld_nb;
	double		d_nb;
	uint64_t	*d_sign;
	__uint128_t	*ld_sign;
	t_bool		neg;

	if (flags->mod == 5)
	{
		ld_nb = va_arg(ap, long double);
		ld_sign = (__uint128_t*)&ld_nb;
		neg = (int)(*ld_sign >> 48) < 0 ? TRUE : FALSE;
		ft_print_float(ld_nb, flags, count, neg);
	}
	else
	{
		d_nb = va_arg(ap, double);
		d_sign = (uint64_t*)&d_nb;
		neg = *d_sign >> 63 == 0 ? FALSE : TRUE;
		ft_print_float((long double)d_nb, flags, count, neg);
	}
}
