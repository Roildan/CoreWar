/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:12:15 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/12 21:16:29 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n, int base)
{
	size_t size;

	size = 1;
	if (base == 10 && n < 0)
		size++;
	while (n /= base)
		size++;
	return (size);
}

char			*ft_itoa_base(int n, int base)
{
	char	*res;
	size_t	size;
	long	nb;
	char	*base_array;

	base_array = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	size = ft_size(n, base);
	if (!(res = ft_strnew(size)))
		return (NULL);
	nb = (long)n;
	if (nb < 0)
	{
		nb *= -1;
		if (base == 10)
			res[0] = '-';
	}
	while (nb || !res[0])
	{
		res[--size] = base_array[nb % base];
		nb /= base;
	}
	return (res);
}
