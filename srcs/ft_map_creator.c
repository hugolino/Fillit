/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/10/06 13:08:24 by rthys            ###   ########.fr       */
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
		map[i] = (char *)malloc(sizeof(char) * (cotes) + 1);
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
		map[i][j] = '\n';
		map[i][j + 1] = '\0';
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

void	ft_prepare_algo(t_coord *cd)
{
	X_M = 0;
	Y_M = 0;
	X_P = 0;
	Y_P = 0;
	NB_P = (ft_countl(BUF) / 4);
	LET = 'A';
	MAP = ft_map_creator(COTE);
	ft_resolve(cd);
}

void	ft_resolve(t_coord *cd)
{
	Y_M = 0;
	printf("RESOLVE\n");
	if (TAB[Y_P][0] == '\n' && Y_P == 0)
		Y_P++;
	while (Y_M < COTE && TAB[Y_P][X_P] != '0')
	{
		X_M = 0;
		while (X_M < COTE && TAB[Y_P][X_P] != '0' && X_P < ft_strlen(TAB[Y_P]))
		{
			printf("Y_P = %zu, X_P = %zu\n", Y_P, X_P);
			printf("Y_M = %zu, X_M = %zu\n", Y_M, X_M);
			printf("TAB[%zu][%zu] = %c\n", Y_P, X_P, TAB[Y_P][X_P]);
			printf("MAP[%zu][%zu] = %c\n", Y_M, X_M, MAP[Y_M][X_M]);
			if (TAB[Y_P][0] == '\n' && Y_P != 0)
			{
				printf("NEXT PIECE\n");
				LET++;
				Y_P++;
				X_P = 0;
				printf("Recursive :\n Y_P = %zu\n X_P = %zu\n Y_M = %zu\n X_M = %zu\n", Y_P, X_P, Y_M, X_M);
				ft_resolve(cd);
				return ;
			}
			if (MAP[Y_M][X_M] == '.' && TAB[Y_P][X_P] != '0')
			{
				printf("JE RENTRE\n");
				//printf("X_P, Y_P : %zu, %zu\n", X_P, Y_P);
				//printf("X_M, Y_M : %zu, %zu\n", X_M, Y_M);
				//sleep(1);
				if (MAP[Y_M][X_M] == '.' && TAB[Y_P][X_P] != '\n' && TAB[Y_P][X_P] != '0')
				{
					printf("CPY LET, trim = %c\n", TAB[Y_P][X_P]);
					if (TAB[Y_P][X_P] == '#')
						MAP[Y_M][X_M] = LET;
					else
						MAP[Y_M][X_M] = '.';
					if (X_P + 1 == ft_strlen(TAB[Y_P]))
					{
						X_P = 0;
						Y_P++;
					}
					else
						X_P++;
					if (X_M + 1 >= COTE && Y_M + 1 < COTE)
					{
						X_M = 0;
						Y_M++;
					}
					else
						X_M++;
				}
					else if (TAB[Y_P][X_P] == '\n')
						break ;
			}
			else if (MAP[Y_M][X_M] >= 'A' && MAP[Y_M][X_M] <= 'Z')
				X_M++;
		}
		if (TAB[Y_P][X_P] != '0')
		{
			X_P = 0;
			Y_P++;
		}
		if (Y_M + 1 < COTE)
			Y_M++;
	}
	printf("strlen YP = %zu\n", ft_strlen(TAB[Y_P]));
	printf("TAB[Y_P] = %c\n", TAB[Y_P][X_P]);
	if ((X_P > COTE) || (TAB[Y_P][X_P] != '0' && ((ft_strlen(TAB[Y_P]) + X_M  >= COTE)) || (Y_M + 1 == COTE && TAB[Y_P][0] == '\n')))
	{
		printf("BIGGER MAP, COTE = %zu\n", COTE);
		COTE++;
		X_P = 0;
		Y_P = 0;
		LET = 'A';
		MAP = ft_map_creator(COTE);
		ft_resolve(cd);
	}
	printf("END\n");
	return ;
}
