/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 22:52:40 by jrameau           #+#    #+#             */
/*   Updated: 2016/11/19 12:27:23 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

#  include <stdio.h>

# define BUFF_SIZE 42

# define MALLCHECK(x) if (!x) return (-1);

typedef struct  s_file
{
  char          *content;
  int           fd;
  struct s_file *next;
}               t_file;

int		get_next_line(const int fd, char **line);
#endif
