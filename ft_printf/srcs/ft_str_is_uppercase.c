/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:17:34 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/12 20:19:35 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_uppercase(const char *s)
{
	if (!s)
		return (0);
	while (*s)
		if (!ft_isupper(*s++))
			return (0);
	return (1);
}
