/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 16:43:25 by armoulin         ###   ########.fr       */
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
typedef struct 		s_param
{
	char			*str;
	int 			type;
	int 			value;
	char 			*temp;
}					t_param;

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
	t_param			params[MAX_ARGS_NUMBER];
	int 			nb_param;
	size_t			size;
	size_t			nb_line;
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
	char			*label;
	size_t 			label_size;
	size_t			nb_line;
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

/*
** GET_PARAMS.C
*/
void				get_params(char *params, t_cmd *new, t_asm *asmr);

/*
** CHECK_PARAMS.C
*/
void				check_params(t_asm *asmr);

/*
** CHECK_TYPES.C
*/
void				check_types(t_asm *asmr);

/*
** CHECK_LABELS.C
*/
void				check_labels(t_asm *asmr);

#endif