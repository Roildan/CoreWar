/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/12 16:43:25 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler/assembler.h"

static char	*get_param(char *str, int *i)
{
	size_t 	size;
	char 	*param;

	size = 0;
	while (*str && *str != SEPARATOR_CHAR && *str != COMMENT_CHAR)
	{
		size++;
		str++;
		(*i)++;
	}
	if (!(param = ft_strnew(size)))
		exit_msg(ERROR_MALLOC);
	ft_strncpy(param, str - size, size);
	return (param);
}

void		get_params(char *params, t_cmd *new, t_asm *asmr)
{
	int i_params;
	int i;

	i_params = 0;
	i = 0;
	while (params[i])
	{
		if (params[i] == COMMENT_CHAR)
			return ;
		if (i_params == MAX_ARGS_NUMBER)
			exit_msg(ft_strjoin(ft_strjoin(ERROR_ARGS_NUMBER, ERROR_AT),
				ft_itoa(asmr->nb_line)));
		new->params[i_params++].str = get_param(&params[i], &i);
		new->nb_param++;
		if (params[i] == SEPARATOR_CHAR) {
			i++;
			if (!params[i] || params[i] == COMMENT_CHAR)
				exit_msg(ft_strjoin(ft_strjoin(ERROR_SYNTAX, ERROR_AT),
					ft_itoa(asmr->nb_line)));
		}
	}
}