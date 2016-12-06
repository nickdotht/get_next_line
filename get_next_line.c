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

static void    get_correct_file(t_list **file, int fd)
{
	t_list		*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return ;
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
}

int     get_next_line(const int fd, char **line)
{
	char			    buf[BUFF_SIZE + 1];
	static t_list	*file;
	int				    i;
	int				    ret;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	get_correct_file(&file, fd);
	*line = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		MALLCHECK((file->content = ft_strjoin(file->content, buf)));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(file->content))
		return (0);
  i = ft_copyuntil(line, file->content, '\n');
  file->content = file->content + (i + 1);
	return (1);
}
