/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/10/21 19:11:47 by rthys            ###   ########.fr       */
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

void	ft_place_tetri(t_coord *cd, t_etri *tetri)
{
	int		count;

	X_P = 0;
	Y_P = 0;
	Y_FIRST = 0;
	X_FIRST = 0;
	count = 0;
	SAVE = ft_cpy_tab(MAP, cd);
	while (count < 4 && Y_P < LEN && NEWYM < COTE && NEWXM <= COTE && NEWYM >= 0 && NEWXM >= 0)
	{
	if ( count == 0)
		{
			X_FIRST = X_P;
			Y_FIRST = Y_P;
		}
	if (TETRI[Y_P][X_P] == '#' && MAP[NEWYM][NEWXM] == '.')
		{
			MAP[NEWYM][NEWXM] = LET;
			count++;
		}
		if (X_P + 1 < (int)ft_strlen(TETRI[Y_P]))
			X_P++;
		else
		{
			X_P = 0;
			Y_P++;
		}
	}
	if (count != 4)
	{
		MAP = ft_cpy_tab(SAVE, cd);
		return ;
	}
	PLACED = 1;
	ASTOCK++;
	Y_M = 0;
	X_M = 0;
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

void	ft_resolve(t_coord *cd, t_etri *tetri)
{
	if (tetri == NULL)
		return (1);
	Y_M = 0;
	while (Y_M + LEN < COTE)
	{
		X_M = 0;
		while (X_M + LAR - 1 < COTE)
		{
			if (ft_check_tetri(cd, tetri) == 1)
			{
				if (ft_resolve(cd, NEXT) == 1)
					return (1);
				else
					ft_place_tetri(cd, tetri, '.');
			}
			X_M++;
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
