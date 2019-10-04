/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:14:58 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/03/28 15:46:50 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_add_alt(t_flags *flags, char caps, char *str)
{
	flags->alt = FALSE;
	str = ft_str_addi_front(caps, str, 1);
	str = ft_str_addi_front('0', str, 1);
	return (str);
}

static char		*ft_width_zero(t_flags *flags, char *str, char caps)
{
	str = ft_str_addi_front('0', str, flags->width - ft_strlen(str));
	if (flags->alt)
	{
		flags->alt = FALSE;
		if (str[1] != '0')
			str = ft_str_addi_front('0', str, 1);
		str[1] = caps;
	}
	return (str);
}

static char		*ft_width(t_flags *flags, char *str, char caps)
{
	if (flags->alt && (*str || flags->preci == -3))
		str = ft_add_alt(flags, caps, str);
	if (flags->width > (int)ft_strlen(str))
	{
		if (flags->left)
			str = ft_str_addi_back(' ', str, flags->width - ft_strlen(str));
		else
			str = ft_str_addi_front(' ', str, flags->width - ft_strlen(str));
	}
	return (str);
}

void			ft_print_hex(unsigned long nb, t_flags *flags, size_t *count,
							int base)
{
	char		*str;
	char		caps;

	str = ft_ntoa_base(nb, base);
	caps = base == 2 ? 'x' : 'X';
	flags->zero = flags->preci == -1 ? flags->zero : FALSE;
	if (nb == 0 && (!flags->preci || flags->preci == -3))
		str[0] = '\0';
	if (flags->preci > (int)ft_strlen(str))
	{
		str = ft_str_addi_front('0', str, flags->preci - ft_strlen(str));
		if (flags->alt && (nb || flags->mod == 10))
			str = ft_add_alt(flags, caps, str);
	}
	if (flags->width > (int)ft_strlen(str) && flags->zero)
		str = ft_width_zero(flags, str, caps);
	if (flags->width > (int)ft_strlen(str))
		str = ft_width(flags, str, caps);
	if (flags->alt && (nb || (flags->preci <= -2)))
		str = ft_add_alt(flags, caps, str);
	ft_print(str, count);
}
