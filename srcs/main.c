/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:18:58 by hdecaux           #+#    #+#             */
/*   Updated: 2016/09/30 15:40:33 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	**tab;
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE];
	int		cotes;

	tab = NULL;
	cotes = 2;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ret = read(fd, buf, BUFF_SIZE);
		tab = ft_bufcpy(buf);
		//ft_puttab(tab, buf);
		ft_errors(ret, buf, tab);
		ft_sub_trim(tab, buf);
		//tab = ft_map_creator(cotes);
		//ft_free_map(tab, cotes);
		ft_prepare_algo(tab);
	}
	return (0);
}
