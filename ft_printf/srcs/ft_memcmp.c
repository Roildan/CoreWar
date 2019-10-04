/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 22:04:04 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:29:31 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *lhs, const void *rhs, size_t count)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	if (!count)
		return (0);
	ptr1 = (const unsigned char *)lhs;
	ptr2 = (const unsigned char *)rhs;
	i = 0;
	while (i + 1 < count && ptr1[i] == ptr2[i])
		i++;
	return ((int)(ptr1[i] - ptr2[i]));
}
