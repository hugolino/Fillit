/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:18:58 by hdecaux           #+#    #+#             */
/*   Updated: 2016/10/03 14:05:39 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	**tab;
	int		fd;
	int		ret;
	t_coord	*cd;
	size_t	i;

	i = 0;
	cd = (t_coord *)malloc(sizeof(t_coord));
	COTE = 2;
	tab = NULL;
	BUF = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ret = read(fd, BUF, BUFF_SIZE);
		tab = ft_bufcpy(BUF);
		ft_errors(ret, BUF, tab);
		//ft_sub_trim(tab, BUF);
		tab = ft_prepare_algo(tab, cd);
		while (i < COTE)
		{
			printf("%s", tab[i]);
			i++;
		}
		ft_free_map(tab, COTE);
	}
	return (0);
}
