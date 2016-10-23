/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:01:45 by jrameau           #+#    #+#             */
/*   Updated: 2016/10/03 17:36:39 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	char	*str;
	char	c1;
	char	c2;
	char	*s1;

	if (ac != 4 || ft_strlen(av[2]) != 1 || ft_strlen(av[3]) != 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = av[1];
	c1 = av[2][0];
	c2 = av[3][0];
	s1 = str;
	while (*s1)
	{
		if (*s1 == c1)
			*s1 = c2;
		s1++;
	}
	while (*(str))
		write(1, str++, 1);
	write(1, "\n", 1);
	return (0);
}
