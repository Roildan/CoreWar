/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:37:27 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:33:51 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *lhs, const char *rhs)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char *p2;

	i = 0;
	p1 = (const unsigned char *)lhs;
	p2 = (const unsigned char *)rhs;
	while (p1[i] && p1[i] == p2[i])
		i++;
	return ((int)(p1[i] - p2[i]));
}
