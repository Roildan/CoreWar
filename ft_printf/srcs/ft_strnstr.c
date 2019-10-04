/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:11:17 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:32:35 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while (str[i] && i < size)
	{
		j = 0;
		while (i + j < size && str[i + j] && str[i + j] == substr[j])
			j++;
		if (!substr[j])
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
