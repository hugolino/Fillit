/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 13:06:20 by rthys             #+#    #+#             */
/*   Updated: 2016/10/18 17:57:29 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_prepare_stock(t_coord *cd)
{
	t_int	stock;

	stock.i = NB_P - 1;
	while (stock.i >= 0)
	{
		stock.k = 0;
		stock.j = stock.i - 1;
		if (STOCK[stock.i] == NB_P - 1)
			stock.i--;
		else
		{
			while (stock.j >= 0 && stock.i != 0)
			{
				if (STOCK[stock.i] + 1 != STOCK[stock.j])
					stock.k++;
				stock.j--;
			}
			STOCK[stock.i] = STOCK[stock.i] + 1;
			if (stock.k == stock.i)
			{
				ft_place_stock(cd, stock.i + 1);
				return ;
			}
		}
	}
}

void	ft_place_stock(t_coord *cd, int i)
{
	int		j;
	size_t	k;
	int		savei;

	savei = i;
	while (i < (int)NB_P)
	{
		k = 0;
		j = 0;
		while (j < i)
		{
			if (k == STOCK[j])
			{
				k++;
				j = 0;
			}
			else
				j++;
		}
		STOCK[i] = k;
		i++;
	}
	i = savei;
}

t_etri	*ft_chose_stock(t_coord *cd, t_etri *tetri)
{
	tetri = BEGIN;
	while (tetri)
	{
		if (RANK == STOCK[ASTOCK])
		{
			return (tetri);
		}
		tetri = NEXT;
	}
	return (tetri);
}

void	ft_bigger_map(t_coord *cd, t_etri *tetri)
{
	Y_M = 0;
	X_M = 0;
	COTE++;
	MAP = ft_map_creator(COTE);
	tetri = BEGIN;
	ft_resolve(cd, tetri);
}

int		ft_best_map(t_coord *cd)
{
	t_int	dot;

	dot.i = 0;
	dot.k = 0;
	while (dot.i < (int)COTE && dot.k >= 0)
	{
		dot.j = 0;
		while (dot.j < (int)COTE && dot.k >= 0)
		{
			if (MAP[dot.i][dot.j] != '.' && BMAP[dot.i][dot.j] == '.')
				dot.k++;
			else if (MAP[dot.i][dot.j] == '.' && BMAP[dot.i][dot.j] != '.')
				dot.k--;
			dot.j++;
		}
		if (dot.k > 0)
			return (1);
		else if (dot.k < 0)
			return (0);
		dot.i++;
	}
	return (0);
}
