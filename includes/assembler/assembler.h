/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:39:25 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/11 16:43:25 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <fcntl.h>
#include "error.h"
#include "op.h"

/*
** =======================
**  INSTRUCTION STRUCTURE
** =======================
*/
typedef struct		s_cmd t_cmd;
typedef struct		s_cmd
{
	int				op_code;
	char			*label;
	int				size;
	t_cmd			*next;
}					t_cmd;

/*
** =====================
**  ASSEMBLER STRUCTURE
** =====================
*/
typedef struct		s_asm
{
	header_t		header;
	t_cmd			*list;
	t_bool			is_name;
	int 			i_name;
	t_bool			got_name;
	t_bool			is_comment;
	int 			i_comment;
	t_bool			got_comment;
	char			*label;
	int				nb_line;
}					t_asm;

/*
** ===========
**  FUNCTIONS
** ===========
*/

/*
** GET_STR.C
*/
void				get_header(char *line, t_asm *asmr);


/*
** READ_FILE.C
*/
void				read_file(char *file, t_asm *asmr);