/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces_revlsq.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:20:41 by rthys             #+#    #+#             */
/*   Updated: 2016/09/21 17:36:03 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_is_square(char **tab, char *buf, int *pieces)
{
	int i;
	int j;
	
	i = *pieces;
	printf("IT'S HIP TO BE SQUARE\n");
	while (tab[i][0] != '\n' && i < ft_countl(buf))
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i + 1][j] == '#' && tab[i + 1][j + 1] == '#')
			{
				pieces += 5;
				return ("\n##\n##\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_lrevhorl(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	printf("IT'S HIP TO BE LREVHORL\n");
	while (tab[i][0] != '\n' || i < ft_countl(buf))
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j] == '#' \
			&& tab[i + 1][j + 1] == '#' && tab[i + 1][j + 2] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0\
			&& ft_strcmp(ft_is_t_left(tab, buf, pieces), "\n.#\n##\n.#\n") != 0\
			&& ft_strcmp(ft_is_s_up(tab, buf, pieces), "\n#.\n##\n.#\n") != 0)
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
	printf("IT'S HIP TO BE LREVHORR\n");
	while (tab[i][0] != '\n' || i < ft_countl(buf))
	{
		j = 0;
		while (j < 6 && i < 3 && j < 3)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i][j + 2] == '#' && tab[i + 2][j + 2] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0)
			{
				pieces += 5;
				return ("\n###\n..#\n");
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
	printf("IT'S HIP TO BE LREVVERR\n");
	while (tab[i][0] != '\n' || i < ft_countl(buf))
	{
		j = 0;
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i + 1][j] == '#' && tab[i + 2][j] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0)
			{
				pieces += 5;
				return ("\n##\n#.\n#.\n");
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
			&& tab[i + 2][j] == '#' && tab[i + 2][j + 1] == '#'\
			&& ft_strcmp(ft_is_square(tab, buf, pieces), "\n##\n##\n") != 0)
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
