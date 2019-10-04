/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:37:27 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:31:44 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *lhs, const char *rhs, size_t count)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (!count)
		return (0);
	i = 0;
	p1 = (const unsigned char *)lhs;
	p2 = (const unsigned char *)rhs;
	while (p1[i] && p1[i] == p2[i] && i < count - 1)
		i++;
	return ((int)(p1[i] - p2[i]));
}
