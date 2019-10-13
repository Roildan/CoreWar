/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/12 16:43:25 by lpoinsot         ###   ########.fr       */
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
	exit_msg(ft_strjoin(ERROR_AT, ft_itoa(asmr->nb_line)));
	return -1;
}

static void		get_all_op(char **tab, int i, t_asm *asmr)
{
	t_cmd	*new;

	new = new_elem();
	if (asmr->label)
	{
		new->label = asmr->label;
		asmr->label = NULL;
	}
	new->op_code = get_op_code(tab[i], asmr);
	asmr->list = add_elem(asmr->list, new);
}

// DEBUG FUNCTION
/*
static void		print_tab_split(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_printf("[%s] ", tab[i++]);
	ft_putchar('\n');
}*/

void			get_op(char *line, t_asm *asmr)
{
	char 	**tab;
	int 	i;

	i = 0;
	if (!(tab = ft_strsplit(line, ' ')))
		exit_msg(ERROR_MALLOC);
	if (check_label(tab[i], asmr))
		get_label(tab[i++], asmr);
	if (tab[i] && tab[i][0] != COMMENT_CHAR)
		get_all_op(tab, i++, asmr);
	ft_freetabsplit(tab);
}