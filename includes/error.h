/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:42:00 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 16:59:52 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_MALLOC			"Could not perform malloc"
# define USAGE_ASM 				"Usage ./asm <sourcefile.s>"
# define ERROR_FILE				"Can't read source file "
# define ERROR_AT 				" at line "
# define ERROR_SYNTAX			"Syntax error"
# define ERROR_UNEXPECTED		"Unexpected symbol"
# define ERROR_LABEL_CHAR		"Wrong label's char"
# define ERROR_OP_NAME			"Instruction name unknown"
# define ERROR_ARGS_NUMBER		"Too many arguments"
# define ERROR_NAME_LENGTH		"Champion's name is too long"
# define ERROR_COMMENT_LENGTH	"Comment is too long"
# define ERROR_CHAMP_SIZE		"Champion's size is too big"
# define ERROR_PARAM_VAL		"Wrong argument's value"
# define ERROR_PARAM_TYPE		"Wrong argument's type"
# define ERROR_LABEL_DUPLICATE	"The following label already exist: "
# define ERROR_LABEL_ALONE		"The following label doesn't have an associate cmd: "
# define ERROR_LABEL_UNKNOW		"The following label doesn't exist: "
# define ERROR_LABEL_CMD		"The following label refer to his own command: "

/*
** ===========
**  FUNCTIONS
** ===========
*/

/*
** ERROR.C
*/
void	exit_msg(char *error_msg);

#endif