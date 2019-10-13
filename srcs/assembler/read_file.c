/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/12 16:43:25 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler/assembler.h"

static void	handle_line(char *line, t_asm *asmr)
{
	while (*line && ft_isspace(*line))
		line++;
	if (!(*line) || *line == COMMENT_CHAR)
		return ;
	/*
	** Header completement gerer:
	**   Name et Comment récupérés avec gestion du multiligne. 
	**   Gestion des erreurs de tailles et de syntax.
	**	 Voir GET_HEADER.C pour le code.
	*/
	else if (!asmr->got_name || !asmr->got_comment)
		get_header(line, asmr);

	/*
	** Instruction en partie gérée:
	**   Utilisation d'un SplitWhiteSpace pour séparer chaque élément.
	**   Label géré qu'il soit au dessus ou inline.
	**   Gestion des erreurs de label (mauvais char ou label vide).
	**   Voir GET_LABEL.C pour le code.
	**   Op Code géré à partir de op_tab.
	**   Gestion de l'erreur d'un nom d'instruction inconnu.
	**   Voir GET_OP.C pour le code.
	**
	** A Faire:
	**   Gérer les paramètres (à stocker dans le tableau de string de t_cmd).
	**   Gérer le potentiel commentaire (juste arreter le parsing
	**		dès qu'un élémnt du tableau commence par '#' en fait
	**      comme fait pour après un label).
	**
	** Du coup tu me dois une demi pipe vu que j'ai pas complétement fini :p
	*/
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
}