/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 22:52:30 by jrameau           #+#    #+#             */
/*   Updated: 2016/12/02 22:11:25 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file *get_correct_file(t_file *file, int fd)
{
	t_file		*tmp;

	if (!file)
	{
		if (!(tmp = ft_filenew(NULL, fd)))
			return (NULL);
	}
	else
	{
		tmp = file;
		if (tmp->fd == fd)
			return (tmp);
		while (tmp->next)
		{
			tmp = tmp->next;
			if (tmp->fd == fd)
				break;
		}
		if (tmp->fd != fd)
		{
			tmp->next->fd = fd;
			tmp->next->content = NULL;
			tmp->next->next = NULL;
		}
	}
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	int						ret;
	char					buf[BUFF_SIZE + 1];
	static t_file	*file;
	int						i;

	// printf("fd: %d\n", fd);

	if (read(fd, buf, 0) < 0 || !line)
		return (-1);
	file = get_correct_file(file, fd);
	if (!file->content || file->content[0] == '\0')
		MALLCHECK((file->content = ft_strnew(1)));
	MALLCHECK((*line = ft_strnew(1)));
	/*
	 *	Read the whole file save it in an array
	 */
	while ((ret = read(file->fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (file->fd == 1)
		{
			MALLCHECK((*line = ft_strjoin(*line, buf)));
		}
		else
		{
			MALLCHECK((file->content = ft_strjoin(file->content, buf)));
		}
	}

	/*
	*		Check the file variable to know if it exists and has text in it
	*		If it does, add everything from the start to the next \n or eol
	*		If not, do nothing.
	*/
	if (file->content && file->content[0] != '\0')
	{
		i = ft_copyuntil(line, file->content, '\n');
		file->content += i + 1;
		return (1);
	}
	return (0);
}
