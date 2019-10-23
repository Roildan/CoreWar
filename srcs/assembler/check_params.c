/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 17:08:31 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler/assembler.h"

static void	check_param(t_cmd *cmd, t_asm *asmr)
{
	// CHECK NB PARAM
	if (cmd->nb_param != asmr->op_tab[cmd->op_code - 1].nb_param)
		exit_msg(ft_strjoin(ft_strjoin(ERROR_ARGS_NUMBER, ERROR_AT),
			ft_itoa(cmd->nb_line)));
	// CHECK TYPE PARAM

	// CHECK VALUE PARAM

	// Store it at the same time ?
}

void		check_params(t_asm *asmr)
{
	t_cmd 	*list;

	list = asmr->list;
	while (list)
	{
		check_param(list, asmr);
		list = list->next;
	}
}