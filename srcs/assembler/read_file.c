/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/12 16:43:25 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler/assembler.h"

static void	handle_line(char *line, t_asm *asmr)
{
	while (*line && ft_isspace(*line))
		line++;
	if (!(*line) || *line == COMMENT_CHAR)
		return ;
	else if (!asmr->got_name || !asmr->got_comment)
		get_header(line, asmr);
	else
		get_op(line, asmr);
}

void		read_file(char *file, t_asm *asmr)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		exit_msg(ft_strjoin(ERROR_FILE, file));
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			exit_msg(ft_strjoin(ERROR_FILE, file));
		asmr->nb_line++;
		handle_line(line, asmr);
		free(line);
	}
	if (asmr->label)
		exit_msg(ft_strjoin(ERROR_LABEL_ALONE, asmr->label));
	close(fd);
}