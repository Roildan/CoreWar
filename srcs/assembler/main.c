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
	asmr->header.magic = COREWAR_EXEC_MAGIC;
	asmr->list = NULL;
	asmr->is_name = FALSE;
	asmr->i_name = 0;
	asmr->got_name = FALSE;
	asmr->is_comment = FALSE;
	asmr->i_comment = 0;
	asmr->got_comment = FALSE;
	asmr->label = NULL;
	asmr->nb_line = 0;
}

int		main(int ac, char **av)
{
	t_asm	asmr;

	if (ac != 2)
		exit_msg(USAGE_ASM);
	init_asm(&asmr);
	read_file(av[1], &asmr);
	ft_printf("Name = %s\n", asmr.header.prog_name);
	ft_printf("Comment = %s\n", asmr.header.comment);
	return (0);
}
