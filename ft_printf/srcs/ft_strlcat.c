/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 23:36:57 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:31:18 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t len_dest;
	size_t len_src;
	size_t i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if (size > len_dest)
	{
		while (*src && i < size - len_dest - 1)
			dest[len_dest + i++] = *src++;
		dest[len_dest + i] = '\0';
		return (len_dest + len_src);
	}
	return (len_src + size);
}
