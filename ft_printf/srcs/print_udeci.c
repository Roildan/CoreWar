/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_udeci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:12:16 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/03/25 18:39:46 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_print_udeci(unsigned long nb, t_flags *flags, size_t *count)
{
	char *str;

	str = ft_ntoa_base(nb, 0);
	if (nb == 0 && !flags->preci)
		str[0] = '\0';
	flags->zero = flags->preci == -1 ? flags->zero : FALSE;
	if (flags->preci > (int)ft_strlen(str))
		str = ft_str_addi_front('0', str, flags->preci - ft_strlen(str));
	if (flags->width > (int)ft_strlen(str) && flags->zero)
		str = ft_str_addi_front('0', str, flags->width - ft_strlen(str));
	if (flags->width > (int)ft_strlen(str))
	{
		if (flags->left)
			str = ft_str_addi_back(' ', str, flags->width - ft_strlen(str));
		else
			str = ft_str_addi_front(' ', str, flags->width - ft_strlen(str));
	}
	ft_print(str, count);
}
