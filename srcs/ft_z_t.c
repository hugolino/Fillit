/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_z_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:38:58 by hdecaux           #+#    #+#             */
/*   Updated: 2016/09/21 17:42:06 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_is_z_up(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	while (i < ft_countl(buf) || tab[i][0] != '\n')
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j - 1] == '#' \
			&& tab[i + 1][j] == '#' && tab[i + 2][j - 1] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0)
			{
				pieces += 5;
				return ("\n.#\n##\n#.\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_t(char **tab, char *buf, int *pieces)
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
			&& tab[i][j + 2] == '#' && tab[i + 1][j + 1] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0)
			{
				pieces += 5;
				return ("\n###\n.#.\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_t_left(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	printf("T_LEFT\n");
	while (i < ft_countl(buf) || tab[i][0] != '\n')
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j - 1] == '#' \
			&& tab[i + 1][j] == '#' && tab[i + 2][j] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0\
			&& ft_strcmp(ft_is_s_up(tab, buf, pieces), "\n#.\n##\n.#\n") != 0)
			{
				pieces += 5;
				return ("\n.#\n##\n.#\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_t_right(char **tab, char *buf, int *pieces)
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
			&& tab[i + 1][j + 1] == '#' && tab[i + 2][j] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0)
			{
				pieces += 5;
				return ("\n#.\n##\n#.\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_t_up(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	printf("IS IT A T O WAT\n");
	while (i < ft_countl(buf) || tab[i][0] != '\n')
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j - 1] == '#' \
			&& tab[i + 1][j] == '#' && tab[i + 1][j + 1] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0\
			&& ft_strcmp(ft_is_t_left(tab, buf, pieces), "\n.#\n##\n.#\n") != 0\
			&& ft_strcmp(ft_is_lverr(tab, buf, pieces), "\n#.\n#.\n##\n") != 0)
			{
				pieces += 5;
				return ("\n.#.\n###\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}
