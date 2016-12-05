/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 22:52:30 by jrameau           #+#    #+#             */
/*   Updated: 2016/12/02 20:14:46 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_correct_file(t_list *file, int fd)
{
	t_list		*tmp;

	if (!file)
	{
		tmp = ft_lstnew(NULL, fd);
	}
	else
	{
		tmp = file;
		while (tmp != NULL)
		{
			if ((int)tmp->content_size == fd)
				return (tmp);
			tmp = tmp->next;
		}
		tmp = ft_lstnew(NULL, fd);
		tmp->next = file;
	}
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	int				i;
	static t_list	*file;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	file = get_correct_file(file, fd);
	MALLCHECK((*line = ft_strnew(1)));
	
	if (ret < BUFF_SIZE && !ft_strlen(file->content))
		return (0);
	return (1);
}
