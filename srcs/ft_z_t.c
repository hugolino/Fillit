/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_z_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:38:58 by hdecaux           #+#    #+#             */
/*   Updated: 2016/10/12 13:55:17 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_is_z_up(char **tab, char *buf, int *pieces, int *found)
{
	int i;
	int j;

	i = *pieces;
	while ((i < ft_countl(buf) && tab[i][0] != '\n') && *found == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j - 1] == '#' \
			&& tab[i + 1][j] == '#' && tab[i + 2][j - 1] == '#')
			{
				*found = 1;
				return (".#\n##\n#.\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_t(char **tab, char *buf, int *pieces, int *found)
{
	int i;
	int j;

	i = *pieces;
	while ((i < ft_countl(buf) && tab[i][0] != '\n') && *found == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i][j + 2] == '#' && tab[i + 1][j + 1] == '#')
			{
				*found = 1;
				return ("###\n.#.\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_t_left(char **tab, char *buf, int *pieces, int *found)
{
	int i;
	int j;

	i = *pieces;
	while ((i < ft_countl(buf) && tab[i][0] != '\n') && *found == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j - 1] == '#' \
			&& tab[i + 1][j] == '#' && tab[i + 2][j] == '#')
			{
				*found = 1;
				return (".#\n##\n.#\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_t_right(char **tab, char *buf, int *pieces, int *found)
{
	int i;
	int j;

	i = *pieces;
	while ((i < ft_countl(buf) && tab[i][0] != '\n') && *found == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j] == '#' \
			&& tab[i + 1][j + 1] == '#' && tab[i + 2][j] == '#')
			{
				*found = 1;
				return ("#.\n##\n#.\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_t_up(char **tab, char *buf, int *pieces, int *found)
{
	int i;
	int j;

	i = *pieces;
	while ((i < ft_countl(buf) && tab[i][0] != '\n') && *found == 0)
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j - 1] == '#'\
			&& tab[i + 1][j] == '#' && tab[i + 1][j + 1] == '#')
			{
				*found = 1;
				return (".#.\n###\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}
