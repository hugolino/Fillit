/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/09/22 17:12:38 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_map_creator(void)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * 50);
	while (i < 50)
	{
		tab[i] = (char *)malloc(sizeof(char) * 50);
		i++;
	}
	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}

char	**ft_prepare_algo(char **trim)
{
	char	**map;
	t_coord	*coord;

	coord->x_map
	map = ft_map_creator();

}
