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

static int 		get_type(char *str)
{
	if (str[0] == 'r')
		return (REG_CODE);
	else if (str[0] == DIRECT_CHAR)
		return (DIR_CODE);
	else
		return (IND_CODE);
}

static void		check_value(t_cmd *cmd, int type, char *str)
{
	if (type == REG_CODE || type == DIR_CODE)
		str++;
	if (*(str + 1) != LABEL_CHAR && (*str == '+' || *str == '-'))
		str++;
	if (*str != LABEL_CHAR && !ft_str_is_numeric(str))
		exit_msg(ft_strjoin(ft_strjoin(ERROR_SYNTAX, ERROR_AT),
			ft_itoa(cmd->nb_line)));
}

static int	 	get_value(t_param *param, int type, char *str)
{
	if (type == REG_CODE || type == DIR_CODE)
		str++;
	if (*str == LABEL_CHAR)
	{
		param->temp = str + 1;
		return (0);
	}
	return ft_atoi(str);
}

static size_t	compute_size(t_cmd *cmd, t_asm *asmr)
{
	size_t	res;
	int 	i;

	res = 1; // 1 octet OP Code
	if (asmr->op_tab[cmd->op_code - 1].have_param_byte)
		res++; // 1 octet Codage des Paramètres
	i = 0;
	while (i < cmd->nb_param)
	{
		if (cmd->params[i].type == REG_CODE)
			res++;
		else if (cmd->params[i].type == IND_CODE)
			res += 2;
		else if (asmr->op_tab[cmd->op_code - 1].is_half_int)
			res += 2;
		else
			res += 4;
		i++;
	}
	return (res);
}

static void		check_param(t_cmd *cmd, t_asm *asmr)
{
	int i;

	if (cmd->nb_param != asmr->op_tab[cmd->op_code - 1].nb_param)
		exit_msg(ft_strjoin(ft_strjoin(ERROR_ARGS_NUMBER, ERROR_AT),
			ft_itoa(cmd->nb_line)));
	i = 0;
	while (i < cmd->nb_param)
	{
		cmd->params[i].type = get_type(cmd->params[i].str);
		check_value(cmd, cmd->params[i].type, cmd->params[i].str);
		cmd->params[i].value = get_value(&(cmd->params[i]),
			cmd->params[i].type, cmd->params[i].str);
		i++;
	}
	cmd->size = compute_size(cmd, asmr);
}

void			check_params(t_asm *asmr)
{
	t_cmd 	*list;

	list = asmr->list;
	while (list)
	{
		check_param(list, asmr);
		list = list->next;
	}
}