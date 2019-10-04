/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabiter_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:37:22 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 18:58:25 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabiter_int(int *tab, size_t size, void (*f)(int))
{
	size_t i;

	if (!tab || !f)
		return ;
	i = 0;
	while (i < size)
		f(tab[i++]);
}
