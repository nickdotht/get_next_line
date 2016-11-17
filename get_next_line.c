/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 22:52:30 by jrameau           #+#    #+#             */
/*   Updated: 2016/11/16 21:04:25 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static int	ret;
	char		buf[BUFF_SIZE + 1];
	char		*curr;
	int			i;
	int			line_complete;
	static char	*tmp_str;
	char		*tmp_str2;

	printf("TEST MY ASS");
	line_complete = 0;
	MALLCHECK((curr = ft_strnew(1)));
	MALLCHECK((*line = ft_strnew(1)));

	/*
	 * If tmp_str has characters in it from previous reading
	 * We check if it has a newline
	 * If it does, we append all the characters that come before
	 * the newline to curr and save the part that comes after it
	 * back into tmp_str for later use.
	*/
	if (tmp_str && ft_strlen(tmp_str))
	{
		if (ft_strchr(tmp_str, '\n') == NULL)
		{
			MALLCHECK((curr = ft_strjoin(curr, tmp_str)));
		}
		else
		{
			MALLCHECK((tmp_str2 = ft_strnew(1)));
			i = 0;
			while (tmp_str[i] && tmp_str[i] != '\n')
				MALLCHECK((curr = ft_strjoinch(curr, tmp_str[i])));
			if (tmp_str[i] == '\n')
				line_complete = 1;
			while (tmp_str[++i])
				MALLCHECK((tmp_str2 = ft_strjoinch(tmp_str2, tmp_str[i])));
			MALLCHECK((tmp_str = ft_strnew(1)));
			MALLCHECK((tmp_str = ft_strjoin(tmp_str, tmp_str2)));
			free(tmp_str2);
		}
	}

	/*
	 *	If the buffer doesn't have a newline
	 *	We simply add it all in curr. else,
	 *	we append all the characters that come before
	 *	the newline to curr and save the part that comes after it
	 *	in a temporary variable for later use.
	*/
	while (!line_complete && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';

		if (ft_strchr(buf, '\n') == NULL)
		{
			MALLCHECK((curr = ft_strjoin(curr, buf)));
			if (ret < BUFF_SIZE)
				line_complete = 1;
		}
		else
		{
			MALLCHECK((tmp_str = ft_strnew(1)));
			i = 0;
			while (buf[i] && buf[i] != '\n')
				MALLCHECK((curr = ft_strjoinch(curr, buf[i++])));
			if (buf[i] == '\n' || (!buf[i] && ret < BUFF_SIZE))
				line_complete = 1;
			while (buf[++i])
				MALLCHECK((tmp_str = ft_strjoinch(tmp_str, buf[i])));
		}
	}
	printf("\nLINE%sLINEEND\n", curr);

	if (line_complete)
		MALLCHECK((*line = ft_strjoin(*line, curr)));
	free(curr);
	printf("Does this work?");
	if (ret < BUFF_SIZE)
	{
		if (tmp_str)
			free(tmp_str);
		return (0);
	}
	printf("WTF DUDE!");
	return (1);
}
