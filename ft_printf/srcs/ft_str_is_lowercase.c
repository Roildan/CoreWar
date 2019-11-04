/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:17:34 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/12 20:18:41 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_is_lowercase(const char *s)
{
	if (!s)
		return (FALSE);
	while (*s)
		if (!ft_islower(*s++))
			return (FALSE);
	return (TRUE);
}
