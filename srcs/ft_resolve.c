/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:48 by rthys             #+#    #+#             */
/*   Updated: 2016/11/14 14:51:11 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		ft_check_tetri(t_coord *cd, t_etri *tetri, t_int *pmap)
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
	ft_place(cd, tetri, LET, pmap);
	return (1);
}

void	ft_place(t_coord *cd, t_etri *tetri, char c, t_int *pmap)
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
}

void	ft_prepare_algo(t_coord *cd, t_etri *tetri)
{
	COTE = ft_sqrt_int((NB_P) * 4);
	MAP = ft_map_creator(COTE);
	tetri = BEGIN;
	while (ft_resolve(cd, tetri) == 0)
	{
		COTE++;
		MAP = ft_map_creator(COTE);
	}
}

int		ft_resolve(t_coord *cd, t_etri *tetri)
{
	t_int *pmap;

	pmap = (t_int *)malloc(sizeof(t_int));
	pmap->k = 0;
	if (tetri == NULL)
		return (1);
	pmap->i = 0;
	while (pmap->i + LEN <= COTE)
	{
		pmap->j = 0;
		while (pmap->j + LAR <= COTE)
		{
			if (ft_check_tetri(cd, tetri, pmap) == 1)
			{
				if (ft_resolve(cd, NEXT) == 1)
					return (1);
				else
					ft_place(cd, tetri, '.', pmap);
			}
			pmap->j++;
		}
		pmap->i++;
	}
	free(pmap);
	return (0);
}
