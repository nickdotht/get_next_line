/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyuntil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 05:49:22 by jrameau           #+#    #+#             */
/*   Updated: 2016/11/26 05:52:26 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copyuntil(char *s, char c)
{
	int		i;
	int		count;
	char	*s2;

	i = -1;
	count = -1;
	while (s[++i])
		if (s[i] == c)
			break ;
	if (!(s2 = ft_strnew(i)))
		return (NULL);
	while (++count < i)
		if (!(s2 = ft_strjoinch(s2, s[count])))
			return (NULL);
	return (s2);
}
