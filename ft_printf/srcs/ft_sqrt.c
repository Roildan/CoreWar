/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:38:44 by armoulin          #+#    #+#             */
/*   Updated: 2019/01/31 14:40:01 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int res;

	if (nb < 1)
		return (0);
	res = 1;
	while (res <= nb / res)
	{
		if (res * res == nb)
			return (res);
		res++;
	}
	return (res);
}
