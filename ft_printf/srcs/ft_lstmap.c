/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:52:54 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/15 19:07:44 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_del(void *content, size_t size)
{
	(void)size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	if (!(res = f(lst)))
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(new = f(lst)))
		{
			ft_lstdel(&res, &ft_del);
			return (NULL);
		}
		ft_lstpushback(&res, new);
	}
	return (res);
}
