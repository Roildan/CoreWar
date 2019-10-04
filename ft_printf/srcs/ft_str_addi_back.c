/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_addi_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:15:18 by armoulin          #+#    #+#             */
/*   Updated: 2019/03/31 13:15:20 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_str_addi_back(char c, char *s, size_t iter)
{
	size_t	i;
	size_t	len;
	char	*res;

	len = ft_strlen(s);
	res = ft_strnew(len + iter);
	ft_strcpy(res, s);
	i = 0;
	while (i < iter)
		res[len + i++] = c;
	free(s);
	return (res);
}
