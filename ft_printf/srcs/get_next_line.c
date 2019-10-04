/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:15:56 by armoulin          #+#    #+#             */
/*   Updated: 2019/07/06 17:47:03 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fdlist	*get_fd(const int fd, t_fdlist **list)
{
	t_fdlist *elem;

	elem = *list;
	while (elem)
	{
		if (fd == elem->fd)
			return (elem);
		elem = elem->next;
	}
	if (!(elem = (t_fdlist *)malloc(sizeof(t_fdlist))))
		return (NULL);
	elem->fd = fd;
	elem->buff = NULL;
	elem->next = *list;
	*list = elem;
	return (elem);
}

static int		make_line(t_fdlist *current, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (current->buff[i] && current->buff[i] != '\n')
		i++;
	if (current->buff[i])
	{
		*line = ft_strsub(current->buff, 0, i);
		tmp = ft_strdup(current->buff + i + 1);
		free(current->buff);
		current->buff = tmp;
	}
	else
	{
		*line = ft_strdup(current->buff);
		free(current->buff);
		current->buff = NULL;
	}
	return (1);
}

static int		end_fd(t_fdlist **fdlist, int fd)
{
	t_fdlist *current;
	t_fdlist *prev;

	current = *fdlist;
	if (current->fd == fd)
		*fdlist = (*fdlist)->next;
	else
	{
		prev = *fdlist;
		current = current->next;
		while (current->fd != fd)
		{
			current = current->next;
			prev = prev->next;
		}
		prev->next = current->next;
	}
	free(current->buff);
	free(current);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_fdlist	*fdlist = NULL;
	t_fdlist		*current;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				res;

	if (!line || fd < 0 || BUFF_SIZE < 1 || !(current = get_fd(fd, &fdlist))
		|| read(fd, buff, 0) == -1)
		return (-1);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (!current->buff)
			current->buff = ft_strnew(0);
		tmp = ft_strjoin(current->buff, buff);
		free(current->buff);
		current->buff = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (res == 0 && (!current->buff || current->buff[0] == '\0'))
		return (end_fd(&fdlist, fd));
	return (make_line(current, line));
}
