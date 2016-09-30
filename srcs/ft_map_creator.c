/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/09/30 11:32:40 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_map_creator(int cotes)//Alloue en fonction de la taille voulue
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (cotes));
	while (i < cotes)
	{
		map[i] = (char *)malloc(sizeof(char) * (cotes + 1));
		i++;
	}
	i = 0;
	while (i < cotes)
	{
		j = 0;
		while (j < cotes)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	return (map);
}

void	ft_free_map(char **map, int cotes) //Free pour realloc et fin
{
	int i;

	i = 0;
	while (i < cotes)
	{
		free(map[i]);
		i++;
	}
}

/*void	ft_prepare_algo(char **trim)
{
	char	**map;
	int		cotes;
	t_coord	*cd;

	cd->x_m = 0;
	cd->y_m = 0;
	cd->x_p = 0;
	cd->y_p = 0;
	cotes = 2;
	map = ft_map_creator();
	map = ft_resolve(map, cd, trim, cotes);
}

char	**ft_resolve(char **map, t_coord *cd, char **trim, int cotes) // Potentiellement utiliser une struct differente pour coordonnees de map et piece
{
	char	**save_map;

	save_map = map;
	while (cd->y_map <= cotes)
	{
		cd->x_map = 0;
		while (cd->x_map <= cotes)
		{
			
		}
	}
}*/
