/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:15:42 by hdecaux           #+#    #+#             */
/*   Updated: 2016/10/26 14:57:28 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		ft_chrn(char *buf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if ((buf[i] == '\n' && buf[i - 1] == '\n') ||\
		(buf[i] == '\n' && buf[i + 1] == '\0'))
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

void	ft_errors(int ret, char *buf, char **tab)
{
	if (ret == -1)
	{
		ft_putstr("error\n");
		exit(0);
	}
	else if (ft_chrn(buf) == 0 || ft_col(buf) == 0 || ft_dot(buf) == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
	else if (ft_diese(tab, buf) == 0 || ft_valid(tab, buf) == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
}
