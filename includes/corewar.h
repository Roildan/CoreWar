/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:46:36 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/04 15:08:04 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "ft_printf/includes/printf.h"

/*
** ====================
**  CHAMPION STRUCTURE
** ====================
*/
typedef struct		s_champ
{
	char			name[PROG_NAME_LENGTH];
	int				id;
	t_bool			is_alive;
}					t_champ;

/*
** ===================
**  PROCESS STRUCTURE
** ===================
*/
typedef struct		s_process t_process;
typedef struct		s_process
{
	int				reg[REG_NUMBER];
	int				pc;
	t_bool			carry;
	int				id;
	int				cycles;
	t_bool			first_instruction;
	t_champ			*champ;
	t_process		*next;
}					t_process;

/*
** ===========================
**  VIRTUAL MACHINE STRUCTURE
** ===========================
*/
typedef struct		s_vm
{
	t_champ		champs[MAX_PLAYERS];
	int			nb_champs;
	int			cycles_to_die;
	char		mem[MEM_SIZE];
	t_process	*process;
}					t_vm;

/*
** ===========
**  FUNCTIONS
** ===========
*/
