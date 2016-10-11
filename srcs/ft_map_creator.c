/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/10/11 20:38:17 by rthys            ###   ########.fr       */
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

void	ft_place_tetri(t_coord *cd)
{
	int		count;

	count = 0;
	X_FIRST = X_P;
	Y_FIRST = Y_P;
	SAVE = ft_cpy_tab(MAP, cd);
	while (count < 4 && TAB[Y_P][0] != '0')
	{
		if (NEWYM >= COTE)
		{
			MAP = SAVE;
			Y_P = Y_FIRST;
			X_P = X_FIRST;
			return ;
		}
		while (TAB[Y_P][X_P]  && count < 4)
		{
			if (TAB[Y_P][X_P] == '#' && MAP[NEWYM][NEWXM] == '.')
			{
				MAP[NEWYM][NEWXM] = LET;
				count++;
			}
			else if ((TAB[Y_P][X_P] == '#' && MAP[NEWYM][NEWXM] != '.'))
			{
				X_P = X_FIRST;
				Y_P = Y_FIRST;
				MAP = SAVE;
				return ;
			}
			X_P++;
		}
		Y_P++;
		X_P = 0;
	}
	LET++;
	Y_M = NEWYM;
	X_M = NEWXM;
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
	if (TABP == '\n' && Y_P == 0)
		Y_P++;
	while (Y_M < COTE && TABP != '0')
	{
		X_M = 0;
		while (Y_M < COTE && X_M < COTE && TABP != '0' && X_P < ft_strlen(TAB[Y_P]))
		{
			if (TABP == '\n' && Y_P != 0)
			{
				Y_P++;
				X_P = 0;
				ft_resolve(cd);
				return ;
			}
			if (MAP[Y_M][X_M] == '.' && TABP != '0')
			{
				if (MAP[Y_M][X_M] == '.' && TABP != '\n' && TABP != '0')
				{
					if (ft_dota(MAP[Y_M], X_M) >= ft_hash(TAB[Y_P], X_P))
						if (TABP == '#')
							ft_place_tetri(cd);
					if (TABP == '.')
						X_P++;
					if (X_M + 1 >= COTE && Y_M + 1 < COTE)
					{
						X_M = 0;
						Y_M++;
					}
					else
						X_M++;
				}
			}
			else if (MAP[Y_M][X_M] >= 'A' && MAP[Y_M][X_M] <= 'Z')
				X_M++;
		}
		if (TABP != '0' && X_P == ft_strlen(TAB[Y_P]) - 1)
		{
			X_P = 0;
			Y_P++;
		}
		if ((X_M == COTE) || (Y_M + 1 < COTE))
			Y_M++;
	}
	if (Y_P != NB_L)
	{
		COTE++;
		X_P = 0;
		Y_P = 0;
		LET = 'A';
		MAP = ft_map_creator(COTE);
		ft_resolve(cd);
	}
	return ;
}
