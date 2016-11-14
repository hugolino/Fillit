/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_z_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:38:58 by hdecaux           #+#    #+#             */
/*   Updated: 2016/11/14 13:08:47 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_z_up(char **tab, char *buf, int *pieces, int *f)
{
	int i;
	int j;

	i = *pieces;
	while ((i < ft_countl(buf) && tab[i][0] != '\n') && *f == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j - 1] == '#' \
			&& tab[i + 1][j] == '#' && tab[i + 2][j - 1] == '#')
			{
				*f = 1;
				return (".#\n##\n#.\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_t(char **tab, char *buf, int *pieces, int *f)
{
	int i;
	int j;

	i = *pieces;
	while ((i < ft_countl(buf) && tab[i][0] != '\n') && *f == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i][j + 2] == '#' && tab[i + 1][j + 1] == '#')
			{
				*f = 1;
				return ("###\n.#.\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_t_left(char **tab, char *buf, int *pieces, int *f)
{
	int i;
	int j;

	i = *pieces;
	while ((i < ft_countl(buf) && tab[i][0] != '\n') && *f == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j - 1] == '#' \
			&& tab[i + 1][j] == '#' && tab[i + 2][j] == '#')
			{
				*f = 1;
				return (".#\n##\n.#\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_t_right(char **tab, char *buf, int *pieces, int *f)
{
	int i;
	int j;

	i = *pieces;
	while ((i < ft_countl(buf) && tab[i][0] != '\n') && *f == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j] == '#' \
			&& tab[i + 1][j + 1] == '#' && tab[i + 2][j] == '#')
			{
				*f = 1;
				return ("#.\n##\n#.\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_t_up(char **tab, char *buf, int *pieces, int *f)
{
	int i;
	int j;

	i = *pieces;
	while ((i < ft_countl(buf) && tab[i][0] != '\n') && *f == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j - 1] == '#'\
			&& tab[i + 1][j] == '#' && tab[i + 1][j + 1] == '#')
			{
				*f = 1;
				return (".#.\n###\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}
