/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:46:36 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 15:11:30 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "op.h"
#include "../ft_printf/includes/printf.h"
#include <inttypes.h>
// uint32_t;
// uint8_t;

/*
** ====================
**  CHAMPION STRUCTURE
** ====================
*/
typedef struct		s_champ
{
	char			name[PROG_NAME_LENGTH];
	char			*file_name;
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
	uint8_t		mem[MEM_SIZE];
	t_process	*process;
	int			nb_process;
	int			dump;
	int			max_checks;
}					t_vm;

/*
** ===========
**  FUNCTIONS
** ===========
*/

/*
** INIT_VM.C
*/
t_champ				*init_champ(char *name, int champ_nb);
t_process			*init_process(void);
t_vm				*init_vm(void);

/*
** MAIN.C
*/
void				create_champ(char *name, int champ_nb, t_vm *vm);
void				get_opt_champs(int ac, char **av, t_vm *vm);
