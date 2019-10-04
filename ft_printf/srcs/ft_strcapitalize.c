/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:45:54 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/12 21:00:22 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	size_t	i;
	int		is_new_word;

	if (!s)
		return (NULL);
	i = 0;
	is_new_word = 1;
	while (s[i])
	{
		if (is_new_word)
		{
			if (ft_isalnum(s[i]))
			{
				is_new_word = 0;
				s[i] = ft_toupper(s[i]);
			}
		}
		else if (ft_isspace(s[i]) || s[i] == '+' || s[i] == '-')
			is_new_word = 1;
		else
			s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}
