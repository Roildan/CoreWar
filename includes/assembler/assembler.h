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

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include <inttypes.h>
# include <fcntl.h>
# include "error.h"
# include "op.h"

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
	char			*params[MAX_ARGS_NUMBER];
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
	t_op			op_tab[16];
	t_header		header;
	t_bool			is_name;
	int 			i_name;
	t_bool			got_name;
	t_bool			is_comment;
	int 			i_comment;
	t_bool			got_comment;
	t_bool			is_label;
	size_t 			label_size;
	char			*label;
	int				nb_line;
	t_cmd			*list;
}					t_asm;

/*
** ===========
**  FUNCTIONS
** ===========
*/

/*
** LIST_TOOLS.C
*/
t_cmd				*new_elem(void);
t_cmd				*add_elem(t_cmd *list, t_cmd *elem);
void				clear_list(t_cmd *list);

/*
** READ_FILE.C
*/
void				read_file(char *file, t_asm *asmr);

/*
** GET_HEADER.C
*/
void				get_header(char *line, t_asm *asmr);

/*
** GET_OP.C
*/
void				get_op(char *line, t_asm *asmr);

/*
** GET_LABEL.C
*/
t_bool				check_label(char *str, t_asm *asmr);
void				get_label(char *label, t_asm *asmr);


#endif