/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:09:24 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/12 19:44:15 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_countstr(char const *s, char c)
{
	size_t	res;

	res = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res++;
			while (*s && *s != c)
				s++;
		}
	}
	return (res);
}

static size_t	ft_countletter(char const *s, char c)
{
	size_t	res;

	res = 0;
	while (*s && *s != c)
	{
		s++;
		res++;
	}
	return (res);
}

static void		ft_freetab(char **tab, size_t i)
{
	while (i--)
		ft_strdel(&tab[i]);
	free(tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	word_size;

	if (!s || !(tab = (char**)malloc((ft_countstr(s, c) + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word_size = ft_countletter(s, c);
			if (!(tab[i] = ft_strnew(word_size)))
			{
				ft_freetab(tab, i);
				return (NULL);
			}
			ft_strncpy(tab[i++], s, word_size);
			s += word_size;
		}
	}
	tab[i] = NULL;
	return (tab);
}
