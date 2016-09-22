/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:15:42 by hdecaux           #+#    #+#             */
/*   Updated: 2016/09/22 11:25:20 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/* Verification du nombre de dieses */

int		ft_diese(char **tab, char *buf)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < ft_countl(buf))
	{
		j = 0;
		while (j < 5)
		{
			if (tab[i][j] == '#')
				count++;
			j++;
		}
		if (tab[i][0] == '\n' || i == ft_countl(buf) - 1)
		{
			if (count != 4)
				return (0);
			count = 0;
		}
		i++;
	}
	return (1);
}

/*Verification que tous les caracteres sont valides ('.' '#' '\n')*/

int		ft_dot(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/*Verification du bon nombre de ligne dans la piece*/

int		ft_chrn(char *buf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if ((buf[i] == '\n' && buf[i - 1] == '\n') || (buf[i] == '\n' && buf[i + 1] == '\0'))
		{
			if (buf[i] == '\n' && buf[i + 1] == '\0')
			{
				j++;
				i++;
			}
			if (j != 4)
				return (0);
		}
		if (buf[i] == '\n' && j != 4)
            j++;
		if (buf[i] == '\n' && buf[i - 1] == '\n' && j == 4)
			j = 0;
		i++;
	}
	return (1);
}

/*Verification du bon nombre de colonne dans la piece*/

int		ft_col(char *buf)
{
	int i;
	int count;

	i = 0;
	while (buf[i + 1])
	{
		count = 0;
		if (buf[i] == '\n' && buf[i - 1] == '\n')
			i++;
		while (buf[i] != '\n')
		{
			count++;
			if (count > 4)
				return (0);
			i++;
		}
		if ((count) != 4)
			return (0);
		i++;
	}
	return (1);
}

/*Fonction regroupant les verifications*/

int		ft_errors(int ret, char *buf, char **tab)
{
	if (ret == -1)
	{
		printf("-1, Echec Read\n");
		return (-1);
	}
	else if (ft_chrn(buf) == 0)
	{
		printf("-1, Mauvais nombre de lignes\n");
		return (-1);
	}
	else if (ft_col(buf) == 0)
	{
		printf("-1, Mauvais nombre de colonnes\n");
		return (-1);
	}
	else if (ft_dot(buf) == 0)
	{
		printf("-1, Caractere invalide\n");
		return (-1);
	}
	else if (ft_diese(tab, buf) == 0)
	{
		printf("-1, Nombre de dieses invalide\n");
		return (-1);
	}
	else if (ft_valid(tab, buf) == 0)
	{
		printf("-1, Piece invalide\n");
		return (-1);
	}
	printf("0, OK\n");
	return (0);
}
