/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:17:10 by rthys             #+#    #+#             */
/*   Updated: 2016/11/14 13:11:07 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_lhorl(char **tab, char *buf, int *pieces, int *f)
{
	int i;
	int j;

	i = *pieces;
	while ((tab[i][0] != '\n' && i < ft_countl(buf)) && *f == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i][j + 2] == '#' && tab[i + 1][j] == '#')
			{
				*f = 1;
				return ("###\n#..\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_lhorr(char **tab, char *buf, int *pieces, int *f)
{
	int i;
	int j;

	i = *pieces;
	while ((tab[i][0] != '\n' && i < ft_countl(buf)) && *f == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j + 2] == '#' && tab[i + 1][j] == '#' \
			&& tab[i + 1][j + 1] == '#' && tab[i + 1][j + 2] == '#')
			{
				*f = 1;
				return ("..#\n###\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_lverr(char **tab, char *buf, int *pieces, int *f)
{
	int i;
	int j;

	i = *pieces;
	while ((tab[i][0] != '\n' && i < ft_countl(buf)) && *f == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j] == '#' \
			&& tab[i + 2][j] == '#' && tab[i + 2][j + 1] == '#')
			{
				*f = 1;
				return ("#.\n#.\n##\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_lverl(char **tab, char *buf, int *pieces, int *f)
{
	int i;
	int j;

	i = *pieces;
	while ((tab[i][0] != '\n' && i < ft_countl(buf)) && *f == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i + 1][j + 1] == '#' && tab[i + 2][j + 1] == '#')
			{
				*f = 1;
				return ("##\n.#\n.#\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}
