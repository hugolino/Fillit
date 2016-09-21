/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:25:50 by hdecaux           #+#    #+#             */
/*   Updated: 2016/09/21 11:38:15 by hdecaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_malloc_tab(char **tab, char *buf)
{
	int		i;

	i = 0;
	if (tab == NULL)
	{
		tab = (char **)malloc(sizeof(char *) * ft_countl(buf) + 1);
		while (i <= ft_countl(buf))
		{
			tab[i] = (char *)malloc(sizeof(char) * 6);
			i++;
		}
	}
	return (tab);
}

int			ft_countl(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void		ft_puttabchar(char **tab, char *buf)
{
	int i;
	int j;

	i = 0;
	while (i < ft_countl(buf))
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			//write(1, &tab[i][j], 1);
			j++;
		}
		i++;
	}
}

char		**ft_bufcpy(char *buf)
{
	char	**tab;
	int		i;
	int		j;
	int		count;

	tab = NULL;
	i = 0;
	count = 0;
	tab = ft_malloc_tab(tab, buf);
	while (buf[count] && i < (ft_countl(buf)))
	{
		j = 0;
		while (j <= 4 && buf[count] && tab[i][j - 1] != '\n')
		{
			if (j == 4)
				tab[i][j] = '\0';
			tab[i][j] = buf[count];
			if ((tab[i][j] != '\n' || tab[i][j] != '.' || tab[i][j] != '#'))
				tab[i][j + 1] = '\0';
			if (buf[count] == '\n' && buf[count - 1] == '\n')
			{
				tab[i][j] = '\n';
			}
			count++;
			j++;
		}
		i++;
	}
	tab[i][0] = '\n';
	return (tab);
}
