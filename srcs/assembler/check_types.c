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

static void	check_param_type_2(t_cmd *cmd, int param_i, t_asm *asmr)
{
	int	type;

	type = cmd->params[param_i].type;
	// 2 ==> T_DIR
	if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 2 &&
		(type == DIR_CODE))
			return ;
	// 1 ==> T_REG
	else if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 1 &&
		(type == REG_CODE))
			return ;
	exit_msg(ft_strjoin(ft_strjoin(ERROR_PARAM_TYPE, ERROR_AT),
		ft_itoa(cmd->nb_line)));
}

static void	check_param_type(t_cmd *cmd, int param_i, t_asm *asmr)
{	
	int	type;

	type = cmd->params[param_i].type;
	// 7 ==> all types
	if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 7)
		return ;
	// 6 ==> T_DIR | T_IND
	else if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 6 &&
		(type == DIR_CODE || type == IND_CODE))
			return ;
	// 5 ==> T_DIR | T_IND
	else if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 5 &&
		(type == REG_CODE || type == IND_CODE))
			return ;
	// 4 ==> T_IND
	else if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 4 &&
		(type == IND_CODE))
			return ;
	// 3 ==> T_REG | T_T_DIR
	else if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 3 &&
		(type == REG_CODE || type == DIR_CODE))
			return ;
	check_param_type_2(cmd, param_i, asmr);
}

void		check_types(t_asm *asmr)
{
	t_cmd 	*list;
	int		i;

	list = asmr->list;
	while (list)
	{
		i = 0;
		while (i < list->nb_param)
		{
			check_param_type(list, i, asmr);
			i++;
		}
		list = list->next;
	}
}