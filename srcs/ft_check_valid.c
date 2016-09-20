/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:56:46 by rthys             #+#    #+#             */
/*   Updated: 2016/01/27 12:11:50 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* Verification de la premiere ligne de la piece */

int		ft_check_first(char **tab, int i)
{
	int j;

	j = 0;
	while (j < 5)
	{
		if (tab[i][j] == '#')
		{
			if (j == 0)
			{
				if (tab[i][j + 1] != '#' && tab[i + 1][j] != '#')
					return (0);
			}
			else if (j == 3)
			{
				if (tab[i][j - 1] != '#' && tab[i + 1][j] != '#')
					return (0);
			}
			else
			{
				if (tab[i][j + 1] != '#' && tab[i][j - 1] != '#' \
				&& tab[i + 1][j] != '#')
					return (0);
			}
		}
		j++;
	}
	return (1);
}

/*Verification de la derniere ligne de la piece*/

int		ft_check_last(char **tab, int i)
{
	int	j;

	j = 0;
	while (j < 5)
	{
		if (tab[i][j] == '#')
		{
			if (j == 0)
			{
				if (tab[i][j + 1] != '#' && tab[i - 1][j] != '#')
					return (0);
			}
			else if (j == 3)
			{
				if (tab[i][j - 1] != '#' && tab[i - 1][j] != '#')
					return (0);
			}
			else
			{
				if (tab[i][j + 1] != '#' && tab[i][j - 1] != '#' \
				&& tab[i - 1][j] != '#')
					return (0);
			}
		}
		j++;
	}
	return (1);
}

/*Verification des autres lignes*/

int		ft_check_lines(char **tab, int i)
{
	int	j;

	j = 0;
	while (j < 5)
	{
		if (tab[i][j] == '#')
		{
			if (j == 0)
			{
				if (tab[i][j + 1] != '#' && tab[i - 1][j] != '#' \
				&& tab[i + 1][j] != '#')
					return (0);
			}
			else if (j == 3)
			{
				if (tab[i][j - 1] != '#' && tab[i - 1][j] != '#' \
				&& tab[i + 1][j] != '#')
					return (0);
			}
			else
			{
				if (tab[i][j + 1] != '#' && tab[i][j - 1] != '#' \
				&& tab[i - 1][j] != '#' && tab[i + 1][j] != '#')
					return (0);
			}
		}
		j++;
	}
	return (1);
}

int		ft_valid(char **tab, char *buf)
{
	int i;

	i = 0;
	while (i < ft_countl(buf))
	{
		if ((i % 5) == 0)
		{
			if (ft_check_first(tab, i) == 0)
				return (0);
		}
		else if (tab[i + 1][0] == '\n')
		{
			if (ft_check_last(tab, i) == 0)
				return (0);
		}
		else if (tab[i][0] == '\n')
			sleep(0);
		else
		{
			if (ft_check_lines(tab, i) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}
