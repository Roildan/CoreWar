/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 02:18:02 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/21 02:24:26 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*res;
	size_t	len;

	len = ft_strlen(str);
	len = len > n ? n : len;
	if (!(res = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(res, str, n));
}
