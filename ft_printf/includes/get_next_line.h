/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:10:02 by armoulin          #+#    #+#             */
/*   Updated: 2019/06/19 13:29:50 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 1024

typedef struct		s_fdlist
{
	int				fd;
	char			*buff;
	struct s_fdlist	*next;
}					t_fdlist;

int					get_next_line(const int fd, char **line);

#endif
