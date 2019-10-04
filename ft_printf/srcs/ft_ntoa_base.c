/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:15:59 by armoulin          #+#    #+#             */
/*   Updated: 2019/03/31 13:16:02 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_base(int base)
{
	char	*basetype;

	if (base == 0)
		basetype = "0123456789";
	else if (base == 1)
		basetype = "01234567";
	else if (base == 2)
		basetype = "0123456789abcdef";
	else
		basetype = "0123456789ABCDEF";
	return (basetype);
}

size_t	ft_get_size(unsigned long int nb, size_t length)
{
	size_t res;

	res = 1;
	while (nb /= length)
		res++;
	return (res);
}

char	*ft_ntoa_base(unsigned long int nb, int base)
{
	char	*res;
	char	*basetype;
	int		i;
	size_t	size_res;
	size_t	size_base;

	basetype = ft_get_base(base);
	size_base = ft_strlen(basetype);
	size_res = ft_get_size(nb, size_base);
	res = ft_strnew(size_res);
	i = size_res - 1;
	while (nb >= size_base)
	{
		res[i--] = basetype[nb % size_base];
		nb /= size_base;
	}
	res[i] = basetype[nb];
	return (res);
}
