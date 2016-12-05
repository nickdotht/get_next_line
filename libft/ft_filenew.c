/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:11:30 by jrameau           #+#    #+#             */
/*   Updated: 2016/12/05 02:11:31 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file	*ft_filenew(void const *content, int fd)
{
	t_file		*file;

	if (!(file = (t_file *)malloc(sizeof(*file))))
		return (NULL);
	if (!content)
	{
		file->content = NULL;
		file->fd = fd;
	}
	else
	{
		if (!(file->content = malloc(fd)))
			return (NULL);
		ft_memcpy(file->content, content, fd);
		file->fd = fd;
	}
	file->next = NULL;
	return (file);
}
