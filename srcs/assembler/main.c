/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/11 17:08:31 by lpoinsot         ###   ########.fr       */
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
	asmr->is_label = FALSE;
	asmr->label_size = 0;
	asmr->label = NULL;
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
		ft_printf("Instruction n°%d:\n", i++);
		if (list->label)
			ft_printf("\tLabel: %s\n", list->label);
		ft_printf("\tOp Code: %d\n", list->op_code);
		j = 0;
		while (j < MAX_ARGS_NUMBER)
		{
			if (list->params[j])
				ft_printf("\tParam %d: %s\n", j + 1, list->params[j]);
			j++;
		}
		ft_printf("\tSize: %d\n", list->size);
		ft_putchar('\n');
		list = list->next;
	}
}

int		main(int ac, char **av)
{
	t_asm	asmr;

	if (ac != 2)
		exit_msg(USAGE_ASM);
	init_asm(&asmr);
	read_file(av[1], &asmr);
	// START DEBUG
	ft_printf("Name = %s\n", asmr.header.prog_name);
	ft_printf("Comment = %s\n\n", asmr.header.comment);
	print_list(asmr.list);
	// END DEBUG
	clear_list(asmr.list);
	return (0);
}
