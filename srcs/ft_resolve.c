/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/10/21 19:34:38 by rthys            ###   ########.fr       */
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

int		ft_check_tetri(t_coord *cd, t_etri *tetri)
{
	Y_P = 0;
	while (Y_P < LEN)
	{
		X_P = 0;
		while (X_P < LAR)
		{
			if (TETRI[Y_P][X_P] == '#' && MAP[NEWYM][NEWXM] != '.')
				return (0);
			X_P++;
		}
		Y_P++;
	}
	ft_place_tetri(cd, tetri, LET);
	return (1);
}

void	ft_place_tetri(t_coord *cd, t_etri *tetri, char c)
{
	Y_P = 0;
	while (Y_P < LEN)
	{
		X_P = 0;
		while (X_P < LAR)
		{
			if (TETRI[Y_P][X_P] == '#')
				MAP[NEWYM][NEWXM] = c;
			X_P++;
		}
		Y_P++;
	}
	Y_P = 0;
	X_P = 0;
}

void	ft_prepare_algo(t_coord *cd, t_etri *tetri)
{	
	COTE = ft_sqrt(NB_P * 4);
	MAP = ft_map_creator(COTE);
	while (ft_resolve(cd, tetri) == 0)
	{
		tetri = BEGIN;
		COTE++;
		MAP = ft_map_creator(COTE);
	}
}

int		ft_resolve(t_coord *cd, t_etri *tetri)
{
	if (tetri == NULL)
		return (1);
	Y_M = 0;
	while (Y_M + LEN < COTE)
	{
		X_M = 0;
		while (X_M + (LAR - 1) <= COTE)
		{
			if (ft_check_tetri(cd, tetri) == 1)
			{
				if (ft_resolve(cd, NEXT) == 1)
					return (1);
				else
					ft_place_tetri(cd, tetri, '.');
			}
			X_M++;
			int i = 0;
			while (i < COTE)
			{
				printf("MAP = %s", MAP[i]);
				i++;
			}
			printf("\n");
		}
		Y_M++;
	}
	return (0);
}

int		ft_sqrt(int nbr)
{
	int sqrt;

	sqrt = 2;
	while (sqrt * sqrt < nbr)
		sqrt++;
	return (sqrt);
}
