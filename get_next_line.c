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
	static int		ret;
	static char		buf[BUFF_SIZE];
	char					*curr_line;
	int						i;
	int						complete;
	static char		*rest_str;
	int						j;
	char					*tmp;

	ret = BUFF_SIZE;
	if (ret < BUFF_SIZE)
	{
		return (0);
	}
	curr_line = ft_strnew(1);
	tmp = ft_strnew(1);
	complete = 0;
	if (rest_str && ft_strlen(rest_str))
	{
		if (ft_strchr(rest_str, '\n') != NULL)
		{
			i = 0;
			while (rest_str[i] != '\n')
				curr_line = ft_strjoinch(curr_line, rest_str[i++]);
			while (rest_str[++i])
				tmp = ft_strjoinch(tmp, rest_str[i]);
			complete = 1;
		}
		else
			curr_line = ft_strjoin(curr_line, rest_str);
		// printf("\nCURRLINEBEFORE%sCURRLINEBEFOREND\n", curr_line);
	}
	rest_str = ft_strnew(1);
	rest_str = ft_strjoin(rest_str, tmp);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		// printf("INSIDEBUF%sINSIDEBUFEND\n", buf);
		if (ft_strchr(buf, '\n') != NULL || ret < BUFF_SIZE)
		{
			i = 0;
			while (buf[i] && buf[i] != '\n' && i < ret && !complete)
				curr_line = ft_strjoinch(curr_line, buf[i++]);
			j = 0;
			if (!i)
				i--;
			while (buf[++i] && i < ret)
				rest_str = ft_strjoinch(rest_str, buf[i]);
			complete = 1;
		}
		else
			curr_line = ft_strjoin(curr_line, buf);
		if (complete)
			break;
	}
	if (!ft_strlen(curr_line))
		return (0);
	// printf("\nOUTSIDEBUF%sJDNKJNDJN\n", buf);
	// printf("\nCURRLINE%sCURRLINE\n", curr_line);
	// printf("\nRESTOFSTRING%sRESTOFSTRINGEND\n", rest_str);
	*line = curr_line;
	return (1);
}

// int		get_next_line(const int fd, char **line)
// {
// 	int		ret;
// 	static char		*buf;
// 	static int		line_count = 1;
// 	int						line_count_copy;
// 	int						i;
// 	int						j;
// 	int						line_len;

// 	line_count_copy = line_count;
// 	line_len = 1;
// 	buf = ft_strnew(BUFF_SIZE);
// 	while ((ret = read(fd, buf, BUFF_SIZE)))
// 	{
// 		i = -1;
// 		while (line_count_copy)
// 		{
// 			while (buf[++i] && line_count_copy)
// 			{
// 				if (buf[i] == '\n' || buf[i] == '\0')
// 				{
// 					line_count_copy--;
// 				}
// 			}
// 		}
// 		i--;
// 		while (buf[--i] != '\n' && i != 0)
// 			line_len++;

// 		if (!(*line = ft_strnew(line_len)))
// 			return (-1);

// 		j = 0;
// 		while (buf[i] != '\n')
// 			(*line)[j++] = buf[i++];
// 		if (buf[i] == '\0')
// 			return (0);
// 	}
// 	line_count++;
// 	return (1);
// }
