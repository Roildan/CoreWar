/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:53:25 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/12 19:41:55 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	size_t	len;

	if (!s)
		return (NULL);
	while (my_isspace(*s))
		s++;
	len = ft_strlen(s);
	while (len && my_isspace(*(s + len - 1)))
		len--;
	if (!(res = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(res, s, len));
}
