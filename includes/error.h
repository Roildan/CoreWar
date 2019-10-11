/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:42:00 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/11 16:59:52 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/printf.h"

#define ERROR_MALLOC "Could not perform malloc"
#define USAGE_ASM "Usage ./asm <sourcefile.s>"
#define ERROR_FILE "Can't read source file "
#define ERROR_AT "Syntax error at line "

/*
** ===========
**  FUNCTIONS
** ===========
*/

/*
** ERROR.C
*/
void	exit_msg(char *error_msg);
