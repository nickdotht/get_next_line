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

int		get_next_line(const int fd, char **line)
{
	int		ret;
	char					buf[BUFF_SIZE + 1];
	static char		*file;
	int						i;
	char					*curr;

	if (!file || file[0] == '\0')
		MALLCHECK((file = ft_strnew(1)));
	MALLCHECK((*line = ft_strnew(1)));
	MALLCHECK((curr = ft_strnew(1)));

	/*
	 *	Read the whole file save it in a variable
	 */
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		MALLCHECK((file = ft_strjoin(file, buf)));
	}

	// printf("FILE IS\n%s\nFILE WAS \n", file);

	/*
	*		Check the file variable to know if it exists and has text in it
	*		If it does, add everything from the start to the next \n or eol
	*		If not, do nothing.
	*/
	if (file && file[0] != '\0')
	{
		i = 0;
		while (file[i] && file[i] != '\n' && file[i] != '\0')
		{
			MALLCHECK((curr = ft_strjoinch(curr, file[i])));
			i++;
		}
		curr[i] = '\0';
		file = file + i + 1;
		// printf("now file is: %s\n", file);
		*line = curr;
		return (1);
	}
	free(curr);
	return (0);
}
