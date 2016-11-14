/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 12:51:39 by rthys             #+#    #+#             */
/*   Updated: 2016/11/14 13:10:36 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_test_l(char **tab, char *buf, int *pieces, int *f)
{
	char	*trim;

	trim = (char *)malloc(sizeof(int) * ft_strlen(buf));
	trim = "";
	if (ft_strcmp(ft_lhorl(tab, buf, pieces, f), "") != 0)
		trim = "###\n#..\n";
	else if (ft_strcmp(ft_lhorr(tab, buf, pieces, f), "") != 0)
		trim = "..#\n###\n";
	else if (ft_strcmp(ft_lverr(tab, buf, pieces, f), "") != 0)
		trim = "#.\n#.\n##\n";
	else if (ft_strcmp(ft_lverl(tab, buf, pieces, f), "") != 0)
		trim = "##\n.#\n.#\n";
	else if (ft_strcmp(ft_lrevhorr(tab, buf, pieces, f), "") != 0)
		trim = "###\n..#\n";
	else if (ft_strcmp(ft_lrevhorl(tab, buf, pieces, f), "") != 0)
		trim = "#..\n###\n";
	else if (ft_strcmp(ft_lrevverr(tab, buf, pieces, f), "") != 0)
		trim = "##\n#.\n#.\n";
	else if (ft_strcmp(ft_lrevverl(tab, buf, pieces, f), "") != 0)
		trim = ".#\n.#\n##\n";
	return (trim);
}

char	*ft_test_t(char **tab, char *buf, int *pieces, int *f)
{
	char	*trim;

	trim = (char *)malloc(sizeof(int) * ft_strlen(buf));
	trim = "";
	if (ft_strcmp(ft_t(tab, buf, pieces, f), "") != 0)
		trim = "###\n.#.\n";
	else if (ft_strcmp(ft_t_left(tab, buf, pieces, f), "") != 0)
		trim = ".#\n##\n.#\n";
	else if (ft_strcmp(ft_t_right(tab, buf, pieces, f), "") != 0)
		trim = "#.\n##\n#.\n";
	else if (ft_strcmp(ft_t_up(tab, buf, pieces, f), "") != 0)
		trim = ".#.\n###\n";
	return (trim);
}

void	ft_read_count(char *argv, t_coord *cd)
{
	FD = open(argv, O_RDONLY);
	RET = read(FD, BUF, BUFF_SIZE);
	ft_count_pieces(cd);
}
