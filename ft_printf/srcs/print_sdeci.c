/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:56:09 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/03/28 16:38:14 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_add_sign(char *str, t_flags *flags, t_bool neg)
{
	if (neg)
		str = ft_str_addi_front('-', str, 1);
	else if (flags->sign)
		str = ft_str_addi_front('+', str, 1);
	else if (flags->space)
		str = ft_str_addi_front(' ', str, 1);
	return (str);
}

static char	*ft_width_zero(char *str, t_flags *flags, t_bool neg)
{
	str = ft_str_addi_front('0', str, flags->width - ft_strlen(str));
	if (neg)
		str[0] = '-';
	else if (flags->sign)
		str[0] = '+';
	else if (flags->space)
		str[0] = ' ';
	return (str);
}

static char	*ft_width(char *str, t_flags *flags, t_bool neg)
{
	str = ft_add_sign(str, flags, neg);
	if (flags->width > (int)ft_strlen(str))
	{
		if (flags->left)
			str = ft_str_addi_back(' ', str, flags->width - ft_strlen(str));
		else
			str = ft_str_addi_front(' ', str, flags->width - ft_strlen(str));
	}
	return (str);
}

void		ft_print_sdeci(long nb, t_flags *flags, size_t *count)
{
	unsigned long		nb_pos;
	char				*str;
	t_bool				neg;

	neg = nb < 0 ? TRUE : FALSE;
	nb_pos = neg ? (unsigned long)-nb : (unsigned long)nb;
	str = ft_ntoa_base(nb_pos, 0);
	if (nb == 0 && !flags->preci)
		str[0] = '\0';
	flags->zero = flags->preci == -1 ? flags->zero : FALSE;
	if (flags->preci > (int)ft_strlen(str))
		str = ft_str_addi_front('0', str, flags->preci - ft_strlen(str));
	if (flags->width > (int)ft_strlen(str) && flags->zero)
		str = ft_width_zero(str, flags, neg);
	else
		str = ft_width(str, flags, neg);
	ft_print(str, count);
}
