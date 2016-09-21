/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:17:10 by rthys             #+#    #+#             */
/*   Updated: 2016/09/21 15:04:03 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_is_lhorl(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	j = 0;
	while (tab[i][0] != '\n' || i < ft_countl(buf))
	{
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i][j + 2] == '#' && tab[i + 1][j] == '#')
			{
				pieces += 5;
				return ("\n###\n#..\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_lhorr(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	j = 0;
	while (tab[i][0] != '\n' || i < ft_countl(buf))
	{
		while (j < 6)
		{
			if (tab[i][j + 2] == '#' && tab[i + 1][j] == '#' \
			&& tab[i + 1][j + 1] == '#' && tab[i + 1][j + 2] == '#')
			{
				pieces += 5;
				return ("\n..#\n###\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_lverr(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	j = 0;
	while (tab[i][0] != '\n' || i < ft_countl(buf))
	{
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i + 1][j] == '#' \
			&& tab[i + 2][j] == '#' && tab[i + 2][j + 1] == '#')
			{
				pieces += 5;
				return ("\n#\n#\n##\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_lverl(char **tab, char *buf, int *pieces)
{
	int i;
	int j;

	i = *pieces;
	j = 0;
	while (tab[i][0] != '\n' || i < ft_countl(buf))
	{
		while (j < 6)
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#' \
			&& tab[i + 1][j + 1] == '#' && tab[i + 2][j + 1] == '#')
			{
				pieces += 5;
				return ("\n##\n.#\n.#\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}
