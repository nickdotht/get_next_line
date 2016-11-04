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
	static int		ret = BUFF_SIZE;
	char					buf[BUFF_SIZE + 1];
	char					*curr_line;
	int						i;
	static char		*rest_str;
	char					*tmp;
	int						complete;

	if (ret < BUFF_SIZE && (rest_str && !ft_strlen(rest_str)))
		return (0);
	complete = 0;
	MALLCHECK( (curr_line = ft_strnew(1)) );
	MALLCHECK( (*line = ft_strnew(1)) );
	MALLCHECK( (tmp = ft_strnew(1)) );
	if (rest_str && ft_strlen(rest_str))
	{
		if (ft_strchr(rest_str, '\n') != NULL)
		{
			i = 0;
			while (rest_str[i] && rest_str[i] != '\n')
				MALLCHECK( (curr_line = ft_strjoinch(curr_line, rest_str[i++])) );
			complete = 1;
			if (rest_str[i + 1])
			{
				while (rest_str[++i])
					MALLCHECK( (tmp = ft_strjoinch(tmp, rest_str[i])) );
				MALLCHECK( (rest_str = ft_strnew(ft_strlen(tmp))) );
				MALLCHECK( (rest_str = ft_strdup(tmp)) );
			}
			else
				MALLCHECK( (rest_str = ft_strnew(1)) );
		}
		else
		{
			MALLCHECK( (curr_line = ft_strjoin(curr_line, rest_str)) );
			MALLCHECK( (rest_str = ft_strnew(1)) );
		}
	}
	else
		MALLCHECK( (rest_str = ft_strnew(1)) );
	while ( !complete && (ret = read(fd, buf, BUFF_SIZE)) )
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n') != NULL)
		{
			i = 0;
			while (buf[i] && buf[i] != '\n')
				MALLCHECK( (curr_line = ft_strjoinch(curr_line, buf[i++])) );
			complete = 1;
			if (buf[i + 1])
				while (buf[++i])
					MALLCHECK( (rest_str = ft_strjoinch(rest_str, buf[i])) );
			break;
		}
		MALLCHECK( (curr_line = ft_strjoin(curr_line, buf)) );
	}
	if (!ret)
		return (0);
	MALLCHECK( (*line = ft_strjoin(*line, curr_line)) );
	return (1);
}
