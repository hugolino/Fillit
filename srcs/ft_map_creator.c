/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/09/28 12:04:08 by rthys            ###   ########.fr       */
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

void	ft_prepare_algo(char **trim)
{
	char	**map;
	int		cotes;
	t_coord	*cd;

	cd->x_m = 0;
	cd->y_m = 0;
	cd->x_p = 0;
	cd->y_p = 0;
	cote = 2;
	map = ft_map_creator();
	map = ft_resolve(map, coord, trim, cotes);
}

char	**ft_resolve(char **map, t_coord *coord, char **trim, int cotes)
{
	char	**save_map;

