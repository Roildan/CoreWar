/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/11 17:08:31 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler/assembler.h"

void	read_file(char *file, t_asm *asmr)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		exit_msg(ft_strjoin(ERROR_FILE, file));
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			exit_msg(ft_strjoin(ERROR_FILE, file));
		handle_line(line, asmr);
		asmr->line++;
		free(line);
	}
}

void	get_info(char *line, t_cmd *asmr)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && line[i] == COMMENT_CHAR)
		return ;
	if (ft_strncmp(*line[i], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		asmr->is_name = TRUE;
		asmr->header.prog_name = get_str(line);
	}
	else if (ft_strcmp(*line[i], COMMENT_CMD_STRING))
	{
		asmr->is_comment = TRUE;
		asmr->header.comment = get_str(line);
	}
	else
		exit_msg(ft_strjoin(ERROR_AT, ft_itoa(asmr->nb_line)));
}

void	handle_line(char *line, t_cmd *asmr)
{
	if (!asmr->got_name || !asmr->got_comment)
		get_info(line, asmr);
}

void	init_asm(t_asm *asmr)
{
	asmr->header.magic = COREWAR_EXEC_MAGIC;
	asmr->list = NULL;
	asmr->is_name = FALSE;
	asmr->got_name = FALSE;
	asmr->is_comment = FALSE;
	asmr->got_comment = FALSE;
	asmr->label = NULL;
	asmr->nb_line = 0;
}

int		main(int ac, char **av)
{
	t_asm	asmr;

	if (ac != 2)
		exit_msg(USAGE_ASM);
	init_asm(&asmr);
	read_file(av[1], &asmr);
	return (0);
}
