/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_addi_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:15:32 by armoulin          #+#    #+#             */
/*   Updated: 2019/03/31 13:15:36 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_str_addi_front(char c, char *s, size_t iter)
{
	size_t	i;
	char	*res;

	res = ft_strnew(ft_strlen(s) + iter);
	i = 0;
	while (i < iter)
		res[i++] = c;
	ft_strcpy(res + i, s);
	free(s);
	return (res);
}
