/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:12:15 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/12 19:22:51 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t size;

	size = 1;
	if (n < 0)
		size++;
	while (n /= 10)
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	char	*res;
	size_t	size;
	long	nb;

	size = ft_size(n);
	if (!(res = ft_strnew(size)))
		return (NULL);
	nb = (long)n;
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
	}
	while (nb || !res[0])
	{
		res[--size] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}
