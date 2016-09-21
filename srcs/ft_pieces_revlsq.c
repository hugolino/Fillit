/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces_revlsq.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:20:41 by rthys             #+#    #+#             */
/*   Updated: 2016/09/21 15:22:52 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_is_square(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	while (tab[i][0] != '\n' || i < ft_countl(buf))
	{
		j = 0;
		while (j < 6)
		{
			
			printf("IT'S HIP TO BE SQUARE\n");
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i + 1][j] == '#' && tab[i + 1][j + 1] == '#')
			{
				pieces += 5;
				return ("\n##\n##\n");
			}
			j++;
		}
		printf("INCREASE i++\n");
		i++;
	}
	return ("");
}

char	*ft_is_lrevhorl(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	while (tab[i][0] != '\n' || i < ft_countl(buf))
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j] == '#' \
			&& tab[i + 1][j + 1] == '#' && tab[i + 1][j + 2] == '#')
			{
				pieces += 5;
				return ("\n#..\n###\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_lrevhorr(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	while (tab[i][0] != '\n' || i < ft_countl(buf))
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i][j + 2] == '#' && tab[i + 2][j + 2] == '#')
			{
				pieces += 5;
				return ("\n###\n#\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_lrevverr(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	while (tab[i][0] != '\n' || i < ft_countl(buf))
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i + 1][j] == '#' && tab[i + 2][j] == '#')
			{
				pieces += 5;
				return ("\n##\n#\n#\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_lrevverl(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	while (tab[i][0] != '\n' || i < ft_countl(buf))
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j + 1] == '#' && tab[i + 1][j + 1] == '#' \
			&& tab[i + 2][j] == '#' && tab[i + 2][j + 1] == '#')
			{
				pieces += 5;
				return ("\n.#\n.#\n##\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}
