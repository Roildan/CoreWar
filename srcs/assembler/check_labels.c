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

static t_cmd	*label_exist(t_param *param, t_cmd *cmd, t_asm *asmr)
{
	t_cmd 	*list;
	size_t	size;

	list = asmr->list;
	size = ft_strlen(param->temp);
	while (list)
	{
		if (list->label && size == ft_strlen(list->label) &&
			!ft_strncmp(param->temp, list->label, size))
		{
			if (list == cmd)
				exit_msg(ft_strjoin(ERROR_LABEL_CMD, list->label));
			return (list);
		}
		list = list->next;
	}
	exit_msg(ft_strjoin(ERROR_LABEL_UNKNOW, param->temp));
	return (NULL);
}

static int		get_label_value(t_cmd *cmd, t_cmd *cmd_label, t_asm *asmr)
{
	int		res_forward;
	int		res_backward;
	t_bool	start;
	t_cmd	*list;
	t_cmd	*temp;

	temp = cmd;
	start = FALSE;
	res_forward = cmd->size;
	res_backward = 0;
	list = asmr->list;
	cmd = cmd->next;
	while (list || cmd)
	{
		if (cmd == cmd_label)
			return (res_forward);
		if (list == cmd_label)
			start = TRUE;
		else if (list == temp)
			return (res_backward);
		if (cmd)
			res_forward += cmd->size;
		if (list && start)
			res_backward -= list->size;
		list = list ? list->next : NULL;
		cmd = cmd ? cmd->next : NULL;
	}
	return (0);
}

static void		valid_param(t_param *param, t_cmd *cmd, t_asm *asmr)
{
	t_cmd *cmd_label;

	if (param->type == REG_CODE
		&& (param->temp || param->value < 1 || param->value > REG_NUMBER))
		exit_msg(ft_strjoin(ft_strjoin(ERROR_PARAM_VAL, ERROR_AT),
			ft_itoa(cmd->nb_line)));
	else if (param->temp)
	{
		cmd_label = label_exist(param, cmd, asmr);
		param->value = get_label_value(cmd, cmd_label, asmr);
		if (param->value < 0)
			param->value = MEM_SIZE + param->value;
	}
}

void			check_labels(t_asm *asmr)
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