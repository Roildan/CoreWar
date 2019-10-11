/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:30:42 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/11 15:41:54 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler/assembler.h"

t_cmd	*new_elem(void)
{
	t_cmd	*elem;

	if (!(elem = (t_cmd *)ft_memalloc(sizeof(t_cmd))))
		exit_msg(ERROR_MALLOC);
	elem->op_code = 0;
	elem->label = NULL;
	elem->size = 0;
	elem->next = NULL;
	return (elem);
}

t_cmd	*add_elem(t_cmd *list, t_cmd *elem)
{
	t_cmd	*cur;

	if (!list)
		return (elem);
	cur = list;
	while (cur->next)
		cur = cur->next;
	cur->next = elem;
	return (list);
}

void	clear_list(t_cmd *list)
{
	t_cmd *cur;

	while (list)
	{
		cur = list;
		if (cur->label)
			free(cur->label);
		list = cur->next;
		free(cur);
	}
}
