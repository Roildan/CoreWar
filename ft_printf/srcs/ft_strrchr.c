/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 00:54:49 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:33:43 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t len;

	len = ft_strlen(str);
	while (len && str[len] != (char)ch)
		len--;
	if (!len && str[len] != (char)ch)
		return (NULL);
	return ((char *)(str + len));
}
