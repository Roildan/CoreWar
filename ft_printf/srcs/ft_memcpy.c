/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:03:30 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:29:37 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	char		*ptr1;
	const char	*ptr2;

	ptr1 = (char *)dest;
	ptr2 = (const char *)src;
	while (count--)
		*ptr1++ = *ptr2++;
	return (dest);
}
