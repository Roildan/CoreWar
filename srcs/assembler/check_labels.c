/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 17:08:31 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler/assembler.h"

static void	valid_param(t_param *param, t_cmd *cmd, t_asm *asmr)
{
	t_cmd	*lab;

	if (param->type == REG_CODE
		&& (param->temp || param->value < 1 || param->value > REG_NUMBER))
		exit_msg(ft_strjoin(ft_strjoin(ERROR_PARAM_VAL, ERROR_AT),
			ft_itoa(cmd->nb_line)));
	else if (param->temp)
	{
		//get_post_label()
		lab = asmr->list;
		lab++;
	}
}

void		check_labels(t_asm *asmr)
{
	t_cmd 	*list;
	int		i;

	list = asmr->list;
	while (list)
	{
		i = 0;
		while (i < list->nb_param)
		{
			valid_param(&(list->params[i]), list, asmr);
			i++;
		}
		list = list->next;
	}
}