/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:29:47 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/03/28 15:45:29 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_pointer(void *p, t_flags *flags, size_t *count)
{
	flags->alt = TRUE;
	if ((unsigned long)p == 0)
	{
		flags->mod = 10;
		if (flags->preci < 0)
			flags->preci = -2;
		else if (!flags->preci)
			flags->preci = -3;
	}
	ft_print_hex((unsigned long)p, flags, count, 2);
}
