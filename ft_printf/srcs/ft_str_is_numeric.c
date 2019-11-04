/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:12:32 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/12 20:14:43 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_is_numeric(const char *s)
{
	if (!s)
		return (FALSE);
	while (*s)
		if (!ft_isdigit(*s++))
			return (FALSE);
	return (TRUE);
}
