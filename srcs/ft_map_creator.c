/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/09/30 15:40:18 by rthys            ###   ########.fr       */
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

void	ft_prepare_algo(char **trim)
{
	char	**map;
	int		cotes;
	t_coord	*cd;

	cd = (t_coord *)malloc(sizeof(t_coord));
	X_M = 0;
	Y_M = 0;
	X_P = 0;
	Y_P = 0;
	cotes = 2;
	(void)trim;
	map = ft_map_creator(cotes);
	//map = ft_resolve(map, cd, trim, cotes);
}

/*char	**ft_resolve(char **map, t_coord *cd, char **trim, int cotes)
{
	
	while (Y_M < cotes && Y_P < NOMBREDEPIECECREERFONCTION)
	{
		while (X_M < cotes)
		{
			if (trim[Y_P][X_P] == '#' && map[Y_M][X_M] == '.')
				map[Y_M][X_M] = trim[Y_P][X_P];
			else if (trim[Y_P][X_P] == '#' && map[Y_M][X_M] == '#')
			{
				if (X_P < (ft_strlen(trim[Y_P])))
					X_P++;
				else
				{
					X_P = 0;
					Y_P++;
				}
			}
		}
	}
}*/
