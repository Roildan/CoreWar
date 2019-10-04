/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 23:36:57 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:31:35 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t count)
{
	size_t len;
	size_t i;

	len = ft_strlen(dest);
	i = 0;
	while (*src && i < count)
		dest[len + i++] = *src++;
	dest[len + i] = '\0';
	return (dest);
}
