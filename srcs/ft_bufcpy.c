/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:25:50 by hdecaux           #+#    #+#             */
/*   Updated: 2016/10/26 14:32:29 by rthys            ###   ########.fr       */
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

char		**ft_bufcpy(char *buf, t_coord *cd)
{
	char	**tab;
	t_int	ct;

	tab = NULL;
	ct.i = 0;
	ct.k = 0;
	tab = ft_malloc_tab(tab, buf);
	while (buf[ct.k] && ct.i < (ft_countl(buf)))
	{
		ct.j = 0;
		while (ct.j <= 4 && buf[ct.k] && tab[ct.i][(ct.j) - 1] != '\n')
		{
			TABCT = buf[ct.k];
			if ((TABCT != '\n' || TABCT != '.' || TABCT != '#'))
				tab[ct.i][(ct.j) + 1] = '\0';
			if (buf[ct.k] == '\n' && buf[ct.k] == '\n')
				TABCT = '\n';
			ct.k++;
			ct.j++;
		}
		TABCT = '\0';
		NB_L = ct.i++;
	}
	tab[ct.i][0] = '0';
	return (tab);
}
