/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 23:25:42 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:31:11 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t count)
{
	size_t i;

	i = 0;
	while (*src && i < count)
		dest[i++] = *src++;
	while (i < count)
		dest[i++] = '\0';
	return (dest);
}
