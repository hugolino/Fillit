/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/10/05 14:06:58 by rthys            ###   ########.fr       */
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
int k = 0;
while (k < 8)
{
	printf("trim : %s", trim[k]);
	k++;
}
	Y_M = 0;
	printf("RESOLVE\n");
	if (trim[Y_P][0] == '\n' && Y_P == 0)
		Y_P++;
	while (Y_M < COTE && trim[Y_P][0] != '0')
	{
		X_M = 0;
		while (X_M < COTE && trim[Y_P][0] != '0' && X_P < ft_strlen(trim[Y_P]))
		{
			if (trim[Y_P][0] == '\n' && Y_P != 0)
			{
				printf("NEXT PIECE\n");
				LET++;
				Y_P++;
				X_P = 0;
				printf("Recursive :\n Y_P = %zu\n X_P = %zu\n Y_M = %zu\n X_M = %zu\n", Y_P, X_P, Y_M, X_M);
				ft_resolve(cd, trim);
			}
			if (MAP[Y_M][X_M] == '.')
			{
				printf("JE RENTRE\n");
				printf("X_P, Y_P : %zu, %zu\n", X_P, Y_P);
				printf("X_M, Y_M : %zu, %zu\n", X_M, Y_M);
				sleep(1);
				if (MAP[Y_M][X_M] == '.' && trim[Y_P][X_P] != '\n')
				{
					printf("CPY LET\n");
					if (trim[Y_P][X_P] == '#')
						MAP[Y_M][X_M] = LET;
					else
						MAP[Y_M][X_M] = '.';
					X_M++;
				}
					else if (trim[Y_P][X_P] == '\n')
					break ;
			}
			else if (MAP[Y_M][X_M] >= 'A' && MAP[Y_M][X_M] <= 'Z')
				X_M++;
			if (X_P < (ft_strlen(trim[Y_P]) - 1))
				X_P++;
			/*else
			{
				printf("X_P = %zu\n", X_P);
				X_P = 0;
				Y_P++;
				printf("Y_P++ = %zu\n", Y_P);
				printf("trim[Y_P][0] = %c\n", trim[Y_P][0]);
				X_M = 0;
				Y_M++;
				printf("Y_M = %zu\n", Y_M);
				printf("COTE = %zu\n", COTE);
			}*/
		}
		X_P = 0;
		Y_P++;
		if (Y_M < COTE)
			Y_M++;
	}
	printf("strlen YP = %zu\n", ft_strlen(trim[Y_P]));
	printf("trim[Y_P] = %c\n", trim[Y_P][X_P]);
	if (trim[Y_P][0] != '0' && ((ft_strlen(trim[Y_P]) + X_M  >= COTE) || (Y_M == COTE && trim[Y_P][0] == '\n')))
	{
		printf("BIGGER MAP, COTE = %zu\n", COTE);
		COTE++;
		X_P = 0;
		Y_P = 0;
		MAP = ft_map_creator(COTE);
		ft_resolve(cd, trim);
	}
	printf("RETOUR :\n Y_P = %zu\n X_P = %zu\n Y_M = %zu\n X_M = %zu\n", Y_P, X_P, Y_M, X_M);
	k = 0;
	while (k < 3)
{
	printf("%s", MAP[k]);
	k++;
}
	return (MAP);
}
