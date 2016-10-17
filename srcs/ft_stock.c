/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 13:06:20 by rthys             #+#    #+#             */
/*   Updated: 2016/10/17 18:02:11 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_prepare_stock(t_coord *cd)
{
	int		i;
	int		j;
	int		k;

	i = NB_P - 1;
	k = 0;
	while (i != 0)
	{
		j = i - 1;
		if (STOCK[i] == NB_P - 1)
			i--;
		else
		{
			while (j >= 0)
			{
				if (STOCK[i] + 1 != STOCK[j])
					k++;
				j--;
			}
			STOCK[i] = STOCK[i] + 1;
			if (k == i)
			{
				ft_place_stock(cd, i + 1);
				return ;
			}
		}
	}
	STOCK[i] = STOCK[i] + 1;
	ft_place_stock(cd, i + 1);
}

void	ft_place_stock(t_coord *cd, int i)
{
	int		j;
	size_t	k;
	int		savei;
	
	savei = 0;
	while (i < (int)NB_P)
	{
		k = 0;
		j = 0;
		while (j < i)
		{
			if (k == STOCK[j])
				k++;
			else
				j++;
		}
		STOCK[i] = k;
		i++;
	}
	i = savei;
}
