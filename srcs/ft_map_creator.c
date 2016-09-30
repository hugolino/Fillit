/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/09/30 16:28:54 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_map_creator(size_t cotes)//Alloue en fonction de la taille voulue
{
	char	**map;
	size_t	i;
	size_t	j;

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

char	**ft_prepare_algo(char **trim, t_coord *cd)
{
	printf("PREPARE\n");
	X_M = 0;
	Y_M = 0;
	X_P = 0;
	Y_P = 0;
	NB_P = (ft_countl(BUF) / 5);
	printf("nb_p = %zd\n", NB_P);
	MAP = ft_map_creator(COTE);
	MAP = ft_resolve(cd, trim);
	return (MAP);
}

/*char	**ft_resolve(t_coord *cd, char **trim)  NON FONCTIONNEL
{
	Y_P = 0;
	Y_M = 0;
	printf("RESOLVE\n");
	while (Y_M < COTE && (Y_P / 5) < NB_P)
	{
		X_M = 0;
		while (X_M < COTE)
		{
			if (trim[Y_P][X_P] == '#' && MAP[Y_M][X_M] == '.')
				MAP[Y_M][X_M] = trim[Y_P][X_P];
			else if ((trim[Y_P][X_P] == '#' && MAP[Y_M][X_M] == '#') || trim[Y_P][X_P] == '.')
			{
				if (X_P < (ft_strlen(trim[Y_P])))
					X_P++;
				else
				{
					X_P = 0;
					Y_P++;
				}
			}
			X_M++;
		}
		Y_M++;
	}
	if (Y_P == NB_P && X_P == (ft_strlen(trim[Y_P] - 1)))
		return (MAP);
	else
	{
		COTE++;
		ft_resolve(cd, trim);
	}
	return (MAP = ft_map_creator(COTE));
}*/
