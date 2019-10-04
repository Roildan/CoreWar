/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:48:59 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:29:20 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	const unsigned char *p;

	p = (const unsigned char *)ptr;
	while (count--)
	{
		if (*p == (unsigned char)ch)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
