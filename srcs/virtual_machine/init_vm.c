/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:21:57 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/11 15:20:23 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/virtual_machine/corewar.h"

t_champ			*init_champ(char *name, int champ_nb)
{
	t_champ		*champ;

	if (!(champ = (t_champ *)ft_memalloc(sizeof(t_champ))))
		exit_msg(ERROR_MALLOC);
	ft_strcpy(champ->name, name);
	champ->id = champ_nb;
	champ->is_alive = TRUE;
	return (champ);
}

t_process		*init_process(void)
{
	t_process	*process;

	if (!(process = (t_process *)ft_memalloc(sizeof(t_process))))
		exit_msg(ERROR_MALLOC);
	process->pc = 0;
	process->carry = 0;
	process->cycles = 0;
	process->id = 0;
	process->first_instruction = TRUE;
	process->champ = NULL;
	process->next = NULL;
	return (process);
}

t_vm			*init_vm(void)
{
	t_vm		*vm;
	
	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		exit_msg(ERROR_MALLOC);
	vm->nb_champs = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->process = NULL;
	vm->nb_process = 1;
	vm->dump = -1;
	vm->max_checks = MAX_CHECKS;
	return (vm);
}
