/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 22:52:30 by jrameau           #+#    #+#             */
/*   Updated: 2016/09/29 22:52:33 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*curr_line;

	curr_line = ft_strnew(1);
	*line = ft_strnew(1);
	while ( (ret = read(fd, buf, BUFF_SIZE)) )
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n') != NULL)
			break;
		curr_line = ft_strjoin(curr_line, buf);
	}
	*line = ft_strjoin(*line, curr_line);
	return (1);
}
