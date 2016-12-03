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

int		get_next_line(const int fd, char **line)
{
	static int	ret;
	char		buf[BUFF_SIZE + 1];
	char		*curr;
	int			i;
	int			line_complete;
	static char	*tmp_str;
	char		*tmp_str2;

	line_complete = 0;
	MALLCHECK((curr = ft_strnew(1)));
	MALLCHECK((*line = ft_strnew(1)));
	if (ret && ret < BUFF_SIZE && tmp_str && tmp_str[0] == '\0')
	{
		free(curr);
		free(tmp_str);
		ret = 0;
		return (0);
	}

	/*
	 * If tmp_str has characters in it from previous reading
	 * We check if it has a newline
	 * If it does, we append all the characters that come before
	 * the newline to curr and save the part that comes after it
	 * back into tmp_str for later use.
	*/
	if (tmp_str && tmp_str[0] != '\0')
	{
		if (ft_strchr(tmp_str, '\n') == NULL)
		{
			curr = tmp_str;
			tmp_str = NULL;
			/*
			 * Find a way to set the line as complete here
			 * if done reading the file
			*/
			printf("ret=%d\n", ret);
		}
		else
		{
			tmp_str2 = ft_strnchr(tmp_str, '\n', 1);
			MALLCHECK((curr = ft_copyuntil(tmp_str, '\n')));
			line_complete = 1;
			tmp_str = tmp_str2;
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
		if (ret < BUFF_SIZE)
			line_complete = 1;
		if (ft_strchr(buf, '\n') == NULL)
		{
			MALLCHECK((curr = ft_strjoin(curr, buf)));
		}
		else
		{
			MALLCHECK((tmp_str = ft_strnew(1)));
			i = 0;
			while (buf[i] != '\n')
				MALLCHECK((curr = ft_strjoinch(curr, buf[i++])));
			line_complete = 1;
			while (buf[++i])
				MALLCHECK((tmp_str = ft_strjoinch(tmp_str, buf[i])));
		}
	}

	/* printf("ret after=%d line_complete=%d\n", ret, line_complete); */
	*line = curr;
	if (line_complete)
		return (1);
	return (0);
}
