/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/10/18 18:40:57 by rthys            ###   ########.fr       */
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
	X_FIRST = 0;
	X_FIRST = 0;
	count = 0;
	SAVE = ft_cpy_tab(MAP, cd);
	while (count < 4 && Y_P < LEN && NEWYM < COTE && NEWXM <= COTE)
	{
		if (TETRI[Y_P][X_P] == '#' && MAP[NEWYM][NEWXM] == '.')
		{
			if (count == 0)
			{
				X_FIRST = X_P;
				Y_FIRST = Y_P;
			}
			MAP[NEWYM][NEWXM] = LET;
			count++;
		}
		if (X_P + 1 < ft_strlen(TETRI[Y_P]))
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
	size_t	i;
	size_t	first;

	i = 0;
	first = 0;
	STOCK = (size_t *)malloc(sizeof(size_t) * NB_P);
	BCOTE = 100;
	while (i < NB_P)
	{
		STOCK[i] = i;
		i++;
	}
	while (ft_check_end(cd) == 0)
	{
		if (first != 0)
			ft_prepare_stock(cd);
		first = 1;
		tetri = BEGIN;
		X_M = 0;
		Y_M = 0;
		COTE = 2;
		MAP = ft_map_creator(COTE);
		ft_resolve(cd, tetri);
	}
}

void	ft_resolve(t_coord *cd, t_etri *tetri)
{
	ASTOCK = 0;
	while (ASTOCK < NB_P && COTE <= BCOTE)
	{
		PLACED = 0;
		if (Y_M >= COTE)
		{
			ft_bigger_map(cd, tetri);
			return ;
		}
		tetri = ft_chose_stock(cd, tetri);
		if (MAP[Y_M][X_M] == '.')
			ft_place_tetri(cd, tetri);
		if (X_M + 1 < COTE && PLACED == 0)
			X_M++;
		else if (X_M + 1 >= COTE && PLACED == 0)

		{
			X_M = 0;
			Y_M++;
		}
	}
	if (COTE < BCOTE || (COTE == BCOTE && ft_best_map(cd) == 1))
	{
		BMAP = ft_cpy_tab(MAP, cd);
		BCOTE = COTE;
	}
}

int		ft_check_end(t_coord *cd)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = NB_P - 1;
	while (i < NB_P)
	{
		if (STOCK[i] != end)
			return (0);
		end--;
		i++;
	}
	return (1);
}
