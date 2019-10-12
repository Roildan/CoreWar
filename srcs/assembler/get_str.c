/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/12 16:43:25 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler/assembler.h"

static void	get_name(char *line, t_asm *asmr)
{
	while (*line && *line != '"')
	{
		if (asmr->i_name > PROG_NAME_LENGTH)
			exit_msg(ERROR_NAME_LENGTH);
		asmr->header.prog_name[asmr->i_name++] = *line++;
	}
	if (*line == '"')
	{
		asmr->is_name = FALSE;
		asmr->got_name = TRUE;
		asmr->header.prog_name[asmr->i_name] = '\0'; 
	}
}

static void	get_comment(char *line, t_asm *asmr)
{
	while (*line && *line != '"')
	{
		if (asmr->i_comment > COMMENT_LENGTH)
			exit_msg(ERROR_COMMENT_LENGTH);
		asmr->header.comment[asmr->i_comment++] = *line++;
	}
	if (*line == '"')
	{
		asmr->is_comment = FALSE;
		asmr->got_comment = TRUE;
		asmr->header.comment[asmr->i_comment] = '\0'; 
	}
}

static void	handle_name(char *line, t_asm *asmr)
{
	line += ft_strlen(NAME_CMD_STRING);
	while (*line == ' ')
		line++;
	if (*line != '"')
		exit_msg(ft_strjoin(ERROR_AT, ft_itoa(asmr->nb_line)));
	line++;
	asmr->is_name = TRUE;
	get_name(line, asmr);
}

static void	handle_comment(char *line, t_asm *asmr)
{
	line += ft_strlen(COMMENT_CMD_STRING);
	while (*line == ' ')
		line++;
	if (*line != '"')
		exit_msg(ft_strjoin(ERROR_AT, ft_itoa(asmr->nb_line)));
	line++;
	asmr->is_comment = TRUE;
	get_comment(line, asmr);
}

void	get_header(char *line, t_asm *asmr)
{
	while (*line && *line == ' ')
		line++;;
	if (!(*line) || *line == COMMENT_CHAR)
		return ;
	else if (asmr->is_name)
		get_name(line, asmr);
	else if (asmr->is_comment)
		get_comment(line, asmr);
	else if (!asmr->got_name
		&& !ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		handle_name(line, asmr);
	else if (!asmr->got_comment
		&& !ft_strncmp(line, COMMENT_CMD_STRING,
						ft_strlen(COMMENT_CMD_STRING)))
		handle_comment(line, asmr);
	else
		exit_msg(ft_strjoin(ERROR_AT, ft_itoa(asmr->nb_line)));
}