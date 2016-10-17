/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/10/17 20:03:34 by rthys            ###   ########.fr       */
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
	count = 0;
	SAVE = ft_cpy_tab(MAP, cd);
	while (count < 4 && Y_M < COTE)
	{
		if (NEWYM >= COTE || NEWXM >= COTE || (TETRI[Y_P][X_P] == '#' && MAP[NEWYM][NEWXM] != '.'))
		{
			if (X_M < COTE - 1)
				X_M++;
			else
			{
				X_M = 0;
				Y_M++;
			}
		}
		else if (TETRI[Y_P][X_P] == '#' && MAP[NEWYM][NEWXM] == '.')
		{
			MAP[NEWYM][NEWXM] = LET;
			count++;
		}
		if (TETRI[Y_P][X_P] != '#' || MAP[NEWYM][NEWXM] == LET)
		{	
			if (X_P + 1 < ft_strlen(TETRI[Y_P]))
				X_P++;
			else
			{
				Y_P++;
				X_P = 0;
			}
		}
	}
	tetri = NEXT;
	if (Y_M >= COTE)
	{
		MAP = SAVE;
		ft_resolve(cd, tetri);
	}
}

void	ft_prepare_algo(t_coord *cd, t_etri *tetri)
{
	size_t	i;

	i = 0;
	X_M = 0;
	Y_M = 0;
	MAP = ft_map_creator(COTE);
	STOCK = (size_t *)malloc(sizeof(size_t) * NB_P);
	(void)tetri;
	while (i < NB_P)
	{
		STOCK[i] = i;
		i++;
	}
	//ft_resolve(cd, tetri)
	size_t meh = 0;
	size_t bah = 0;
	while (meh < ft_factorial(NB_P) && NB_P < 12)
	{
		bah = 0;
		while (bah < NB_P)
		{
			printf("%zu, ", STOCK[bah]);
			bah++;
		}
		printf("\n");
		ft_prepare_stock(cd);
		meh++;
	}
}

void	ft_resolve(t_coord *cd, t_etri *tetri)
{
	while (tetri)
	{
		ft_place_tetri(cd, tetri);
		//BIGGERMAP?
		tetri = NEXT;
	}
	//if (COTE < /*BESTCOTE*/)
	//BESTMAP = MAP;
	/*CONDITION VERIFIER TOUTES POSSIBILITES TESTEES
	  ft_create_stock(cd);
	  tetri = BEGIN;
	  ft_other_resolve;*/
}

size_t	ft_factorial(size_t nb)
{
	if (nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	if (nb > 1)
		nb = nb * ft_factorial(nb - 1);
	return (nb);
}
