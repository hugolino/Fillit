/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_s_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:38:58 by hdecaux           #+#    #+#             */
/*   Updated: 2016/10/26 14:39:43 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_is_line_hor(char **tab, char *buf, int *pieces, int *found)
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
			&& tab[i][j + 2] == '#' && tab[i][j + 3] == '#')
			{
				*found = 1;
				return ("####\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_line_ver(char **tab, char *buf, int *pieces, int *found)
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
			&& tab[i + 2][j] == '#' && tab[i + 3][j] == '#')
			{
				*found = 1;
				return ("#\n#\n#\n#\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_s(char **tab, char *buf, int *pieces, int *found)
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
			&& tab[i + 1][j - 1] == '#' && tab[i + 1][j] == '#')
			{
				*found = 1;
				return (".##\n##.\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_s_up(char **tab, char *buf, int *pieces, int *found)
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
			&& tab[i + 1][j + 1] == '#' && tab[i + 2][j + 1] == '#')
			{
				*found = 1;
				return ("#.\n##\n.#\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}

char	*ft_is_z(char **tab, char *buf, int *pieces, int *found)
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
			&& tab[i + 1][j + 1] == '#' && tab[i + 1][j + 2] == '#')
			{
				*found = 1;
				return ("##.\n.##\n");
			}
			j++;
		}
		i++;
	}
	return ("");
}
