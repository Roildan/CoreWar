/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:12:08 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:29:03 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t count)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	while (count)
	{
		count--;
		*ptr1 = *ptr2;
		if (*ptr1 == (unsigned char)c)
			return ((void *)(ptr1 + 1));
		ptr1++;
		ptr2++;
	}
	return (NULL);
}
