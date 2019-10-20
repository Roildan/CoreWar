/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/12 16:43:25 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler/assembler.h"

static t_bool	is_label_char(char c)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i] && LABEL_CHARS[i] != c)
		i++;
	if (LABEL_CHARS[i])
		return TRUE;
	return FALSE;
}

t_bool			check_label(char *str, t_asm *asmr)
{
	size_t i;
	size_t size;

	if ((size = ft_strlen(str)) == 0)
		exit_msg(ft_strjoin(ERROR_AT, ft_itoa(asmr->nb_line)));
	size--;
	if (str[size] != LABEL_CHAR)
		return FALSE;
	i = 0;
	while (i < size && is_label_char(str[i]))
		i++;
	if (i != size)
		exit_msg(ft_strjoin(ERROR_AT, ft_itoa(asmr->nb_line)));
	asmr->label_size = size;
	return TRUE;
}

void			get_label(char *label, t_asm *asmr)
{
	if (!(asmr->label = ft_strnew(asmr->label_size)))
		exit_msg(ERROR_MALLOC);
	ft_strncpy(asmr->label, label, asmr->label_size);
}