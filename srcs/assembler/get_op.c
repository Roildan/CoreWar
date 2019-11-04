/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/12 16:43:25 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler/assembler.h"

static int		get_op_code(char *str, t_asm *asmr)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(str, asmr->op_tab[i].name) == 0)
			return asmr->op_tab[i].op_code;
		i++;
	}
	exit_msg(ft_strjoin(ft_strjoin(ERROR_OP_NAME, ERROR_AT),
			ft_itoa(asmr->nb_line)));
	return -1;
}

static char		*one_str(char **tab, int i)
{
	size_t	size;
	int		j;
	char 	*res;

	size = 0;
	j = i;
	while (tab[j])
		size += ft_strlen(tab[j++]);
	if (!(res = ft_strnew(size)))
		exit_msg(ERROR_MALLOC);
	while (tab[i])
		ft_strcat(res, tab[i++]);
	return (res);
}

static void		get_all_op(char **tab, int i, t_asm *asmr)
{
	t_cmd	*new;
	char 	*params;

	new = new_elem();
	if (asmr->label)
	{
		new->label = asmr->label;
		asmr->label = NULL;
		asmr->label_size = 0;
	}
	new->nb_line = asmr->nb_line;
	new->op_code = get_op_code(tab[i++], asmr);
	params = one_str(tab, i);
	get_params(params, new, asmr);
	asmr->list = add_elem(asmr->list, new);
	free(params);
}

void			get_op(char *line, t_asm *asmr)
{
	char 	**tab;
	int 	i;

	i = 0;
	if (!(tab = ft_splitwhite(line)))
		exit_msg(ERROR_MALLOC);
	if (!asmr->label && check_label(tab[i], asmr))
		get_label(tab[i++], asmr);
	if (tab[i] && tab[i][0] != COMMENT_CHAR)
		get_all_op(tab, i++, asmr);
	ft_freetabsplit(tab);
}