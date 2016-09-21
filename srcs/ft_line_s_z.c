/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_s_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:38:58 by hdecaux           #+#    #+#             */
/*   Updated: 2016/09/21 16:01:26 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_is_line_hor(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	while (i < ft_countl(buf) || tab[i][0] != '\n')
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i][j + 2] == '#' && tab[i][j + 3] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0)
			{
				pieces += 5;
				return ("\n####\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_line_ver(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	while (i < ft_countl(buf) || tab[i][0] != '\n')
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j] == '#' \
			&& tab[i + 2][j] == '#' && tab[i + 3][j] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0)
			{
				pieces += 5;
				return ("\n#\n#\n#\n#\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_s(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	while (i < ft_countl(buf) || tab[i][0] != '\n')
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i + 1][j - 1] == '#' && tab[i + 1][j] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0)
			{
				pieces += 5;
				printf("IT'S NOT AN S\n");
				return ("\n.##\n##.\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_s_up(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	while (i < ft_countl(buf) || tab[i][0] != '\n')
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j] == '#' \
			&& tab[i + 1][j + 1] == '#' && tab[i + 2][j + 1] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0)
			{
				pieces += 5;
				return ("\n#.\n##\n.#\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_z(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	while (i < ft_countl(buf) || tab[i][0] != '\n')
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i + 1][j + 1] == '#' && tab[i + 1][j + 2] == '#'
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0)
			{
				pieces += 5;
				return ("\n##.\n.##\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}
