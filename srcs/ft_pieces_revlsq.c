/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces_revlsq.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:20:41 by rthys             #+#    #+#             */
/*   Updated: 2016/11/14 13:06:45 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_square(char **tab, char *buf, int *pieces, int *f)
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
			&& tab[i + 1][j] == '#' && tab[i + 1][j + 1] == '#')
			{
				*f = 1;
				return ("##\n##\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_lrevhorl(char **tab, char *buf, int *pieces, int *f)
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
			&& tab[i + 1][j + 1] == '#' && tab[i + 1][j + 2] == '#')
			{
				*f = 1;
				return ("#..\n###\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_lrevhorr(char **tab, char *buf, int *pieces, int *f)
{
	int i;
	int j;

	i = *pieces;
	while ((tab[i][0] != '\n' && i < ft_countl(buf)) && *f == 0)
	{
		j = 0;
		while (j < 6 && i < 3 && j < 3)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i][j + 2] == '#' && tab[i + 1][j + 2] == '#')
			{
				*f = 1;
				return ("###\n..#\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_lrevverr(char **tab, char *buf, int *pieces, int *f)
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
			&& tab[i + 1][j] == '#' && tab[i + 2][j] == '#')
			{
				*f = 1;
				return ("##\n#.\n#.\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_lrevverl(char **tab, char *buf, int *pieces, int *f)
{
	int i;
	int j;

	i = *pieces;
	while ((tab[i][0] != '\n' && i < ft_countl(buf)) && *f == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j + 1] == '#' && tab[i + 1][j + 1] == '#' \
			&& tab[i + 2][j] == '#' && tab[i + 2][j + 1] == '#')
			{
				*f = 1;
				return (".#\n.#\n##\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}
