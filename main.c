/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:18:58 by hdecaux           #+#    #+#             */
/*   Updated: 2016/09/22 16:43:42 by rthys            ###   ########.fr       */
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

	tab = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ret = read(fd, buf, BUFF_SIZE);
		tab = ft_bufcpy(buf);
		//ft_puttab(tab, buf);
		ft_errors(ret, buf, tab);
		//ft_sub_trim(tab, buf);
		ft_map_creator();
	}
	return (0);
}
