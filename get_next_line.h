/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 22:52:40 by jrameau           #+#    #+#             */
/*   Updated: 2016/09/29 22:52:42 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

# define BUFF_SIZE 2

# define MALLCHECK(x) if (!x) return (NULL);

int		get_next_line(const int fd, char **line);
#endif
