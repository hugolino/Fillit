/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/10/04 11:20:30 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_map_creator(size_t cotes)
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

void	ft_free_map(char **map, size_t cotes)
{
	size_t	i;

	i = 0;
	while (i < cotes)
	{
		free(map[i]);
		i++;
	}
}

char	**ft_prepare_algo(char **trim, t_coord *cd)
{
	X_M = 0;
	Y_M = 0;
	X_P = 0;
	Y_P = 0;
	NB_P = (ft_countl(BUF) / 4);
	LET = 'A';
	MAP = ft_map_creator(COTE);
	MAP = ft_resolve(cd, trim);
	return (MAP);
}

char	**ft_resolve(t_coord *cd, char **trim)
{
	Y_M = 0;
	printf("RESOLVE\n");
	while (Y_M <= COTE && (Y_P / 4) <= NB_P)
	{
		X_M = 0;
		while (X_M <= COTE && (Y_P / 4) <= NB_P)
		{
			if (trim[Y_P][0] == '\n')
			{
				printf("NEXT PIECE\n");
				LET++;
				Y_P++;
				X_P = 0;
				printf("Recursive :\n Y_P = %zu\n X_P = %zu\n Y_M = %zu\n", Y_P, X_P, Y_M);
				ft_resolve(cd, trim);
			}
			if (MAP[Y_M][X_M] == '.')
			{
				if (trim[Y_P][X_P] == '#')
					MAP[Y_M][X_M] = LET;
				else if (trim[Y_P][X_P] == '\n')
					MAP[Y_M][X_M] = trim[Y_P][X_P];
				X_M++;
			}
			else if (MAP[Y_M][X_M] == '#')
				X_M++;
			if (X_P < (ft_strlen(trim[Y_P]) - 1))
				X_P++;
			else
			{
				X_P = 0;
				Y_P++;
			}
		}
		Y_M++;
	}
	if (X_M == COTE && Y_M == COTE)
	{
		COTE++;
		ft_prepare_algo(trim, cd);
	}
	printf("RETOUR :\n Y_P = %zu\n X_P = %zu\n Y_M = %zu\n", Y_P, X_P, Y_M);
	return (MAP);
}
