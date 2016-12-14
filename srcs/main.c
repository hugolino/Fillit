/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:18:58 by hdecaux           #+#    #+#             */
/*   Updated: 2016/10/26 15:03:05 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_coord	*cd;
	t_etri	*tetri;
	int		i;

	i = -1;
	cd = (t_coord *)malloc(sizeof(t_coord));
	TAB = NULL;
	BUF = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (argc == 2)
	{
		ft_read_count(argv[1], cd);
		TAB = ft_bufcpy(BUF, cd);
		ft_errors(RET, BUF, TAB);
		BUF = ft_sub_trim(TAB, BUF);
		TAB = ft_bufcpy(BUF, cd);
		tetri = ft_make_list(cd);
		ft_prepare_algo(cd, tetri);
		while (++i < COTE)
			ft_putstr(MAP[i]);
		free(tetri);
	}
	else
		ft_putstr("error\n");
	free(cd);
	return (0);
}
