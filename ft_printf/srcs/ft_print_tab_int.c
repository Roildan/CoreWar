/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:34:36 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 18:18:18 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab_int(int *tab, size_t size)
{
	if (!tab)
		return ;
	ft_tabiter_int(tab, size, &ft_putnbr);
}
