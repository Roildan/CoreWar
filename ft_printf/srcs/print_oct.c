/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:45:59 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/03/27 18:46:57 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_width(char *str, t_flags *flags)
{
	if (flags->left)
		str = ft_str_addi_back(' ', str, flags->width - ft_strlen(str));
	else
		str = ft_str_addi_front(' ', str, flags->width - ft_strlen(str));
	return (str);
}

void			ft_print_oct(unsigned long nb, t_flags *flags, size_t *count)
{
	char		*str;
	int			i;

	str = ft_ntoa_base(nb, 1);
	if (nb == 0 && !flags->preci)
		str[0] = '\0';
	if (flags->preci > (int)ft_strlen(str))
		str = ft_str_addi_front('0', str, flags->preci - ft_strlen(str));
	if (flags->alt && ((flags->preci < (int)ft_strlen(str) && nb)
				|| (!nb && !flags->preci)))
	{
		i = flags->preci - (int)ft_strlen(str);
		i = i > 0 ? i : 1;
		str = ft_str_addi_front('0', str, i);
	}
	flags->zero = flags->preci == -1 ? flags->zero : FALSE;
	if (flags->width > (int)ft_strlen(str) && flags->zero)
		str = ft_str_addi_front('0', str, flags->width - ft_strlen(str));
	if (flags->width > (int)ft_strlen(str))
		str = ft_width(str, flags);
	ft_print(str, count);
}
