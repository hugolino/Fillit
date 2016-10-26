/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 12:51:39 by rthys             #+#    #+#             */
/*   Updated: 2016/10/26 14:52:44 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_test_l(char **tab, char *buf, int *pieces, int *found)
{
	char	*trim;

	trim = (char *)malloc(sizeof(int) * ft_strlen(buf));
	trim = "";
	if (ft_strcmp(ft_is_lhorl(tab, buf, pieces, found), "") != 0)
		trim = "###\n#..\n";
	else if (ft_strcmp(ft_is_lhorr(tab, buf, pieces, found), "") != 0)
		trim = "..#\n###\n";
	else if (ft_strcmp(ft_is_lverr(tab, buf, pieces, found), "") != 0)
		trim = "#.\n#.\n##\n";
	else if (ft_strcmp(ft_is_lverl(tab, buf, pieces, found), "") != 0)
		trim = "##\n.#\n.#\n";
	else if (ft_strcmp(ft_is_lrevhorr(tab, buf, pieces, found), "") != 0)
		trim = "###\n..#\n";
	else if (ft_strcmp(ft_is_lrevhorl(tab, buf, pieces, found), "") != 0)
		trim = "#..\n###\n";
	else if (ft_strcmp(ft_is_lrevverr(tab, buf, pieces, found), "") != 0)
		trim = "##\n#.\n#.\n";
	else if (ft_strcmp(ft_is_lrevverl(tab, buf, pieces, found), "") != 0)
		trim = ".#\n.#\n##\n";
	return (trim);
}

char	*ft_test_t(char **tab, char *buf, int *pieces, int *found)
{
	char	*trim;

	trim = (char *)malloc(sizeof(int) * ft_strlen(buf));
	trim = "";
	if (ft_strcmp(ft_is_t(tab, buf, pieces, found), "") != 0)
		trim = "###\n.#.\n";
	else if (ft_strcmp(ft_is_t_left(tab, buf, pieces, found), "") != 0)
		trim = ".#\n##\n.#\n";
	else if (ft_strcmp(ft_is_t_right(tab, buf, pieces, found), "") != 0)
		trim = "#.\n##\n#.\n";
	else if (ft_strcmp(ft_is_t_up(tab, buf, pieces, found), "") != 0)
		trim = ".#.\n###\n";
	return (trim);
}

void	ft_read_count(char *argv, t_coord *cd)
{
	FD = open(argv, O_RDONLY);
	RET = read(FD, BUF, BUFF_SIZE);
	ft_count_pieces(cd);
}
