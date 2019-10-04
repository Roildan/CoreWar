/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:11:17 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:32:43 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *substr)
{
	size_t i;
	size_t j;

	i = 0;
	if (!*str && !*substr)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == substr[j])
			j++;
		if (!substr[j])
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
