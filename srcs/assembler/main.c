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

void	init_asm(t_asm *asmr)
{
	get_op_tab(asmr->op_tab);
	asmr->header.magic = COREWAR_EXEC_MAGIC;
	asmr->is_name = FALSE;
	asmr->i_name = 0;
	asmr->got_name = FALSE;
	asmr->is_comment = FALSE;
	asmr->i_comment = 0;
	asmr->got_comment = FALSE;
	asmr->label = NULL;
	asmr->label_size = 0;
	asmr->nb_line = 0;
	asmr->list = NULL;
}

// DEBUG FUNCTION
static void		print_list(t_cmd *list)
{
	int i;
	int j;

	i = 1;
	while (list)
	{
		ft_printf("Instruction n°%d (line: %lu):\n", i++, list->nb_line);
		if (list->label)
			ft_printf("\tLabel: %s\n", list->label);
		ft_printf("\tOp Code: %d\n", list->op_code);
		j = 0;
		while (j < list->nb_param)
		{
			ft_printf(
				"\tParam %d:\n\t\tstr: %s\n\t\ttype: %d\n\t\tvalue: %d\n\t\ttemp: %s\n",
				j + 1, list->params[j].str, list->params[j].type,
				list->params[j].value, list->params[j].temp);
			j++;
		}
		ft_printf("\tSize: %d\n", list->size);
		ft_putchar('\n');
		list = list->next;
	}
}

static unsigned int 	get_prog_size(t_cmd *list)
{
	unsigned int 	res;

	res = 0;
	while (list)
	{
		res += list->size;
		list = list->next;
	}
	if (res > CHAMP_MAX_SIZE)
		exit_msg(ERROR_CHAMP_SIZE);
	return (res);
}

int		main(int ac, char **av)
{
	t_asm	asmr;

	if (ac != 2)
		exit_msg(USAGE_ASM);
	init_asm(&asmr);
	read_file(av[1], &asmr);
	check_params(&asmr);
	check_labels(&asmr);
	asmr.header.prog_size = get_prog_size(asmr.list);
	// START DEBUG
	ft_printf("Name = %s\n", asmr.header.prog_name);
	ft_printf("Comment = %s\n", asmr.header.comment);
	ft_printf("Prog_Size = %u\n\n", asmr.header.prog_size);
	print_list(asmr.list);
	// END DEBUG
	clear_list(asmr.list);
	return (0);
}
