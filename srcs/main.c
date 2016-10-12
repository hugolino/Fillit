/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:18:58 by hdecaux           #+#    #+#             */
/*   Updated: 2016/10/12 18:49:07 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	t_coord	*cd;
	//t_etri	*tetri;
	size_t	i;

	i = 0;
	cd = (t_coord *)malloc(sizeof(t_coord));
	COTE = 2;
	TAB = NULL;
	BUF = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ret = read(fd, BUF, BUFF_SIZE);
		ft_count_pieces(cd);
		TAB = ft_bufcpy(BUF, cd);
		ft_errors(ret, BUF, TAB);
		BUF = ft_sub_trim(TAB, BUF);
		TAB = ft_bufcpy(BUF, cd);
		ft_prepare_algo(cd);
		while (i < COTE)
		{
			printf("%s", MAP[i]);
			i++;
		}
		/*tetri = ft_make_list(cd);
		while (tetri)
		{
			size_t k = 0;
			while (k < LEN)
			{
				printf("%s", TETRI[k]);
				k++;
			}
			printf("\n");
			tetri = NEXT;
		}
		free(tetri);*/
		free(cd);
	}
	return (0);
}
