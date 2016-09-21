/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:52:42 by rthys             #+#    #+#             */
/*   Updated: 2016/09/21 15:21:41 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_trim(char **tab, char *buf, int *pieces)
{
 	char	*trim;
	
	trim = (char *)malloc(sizeof(char) * ft_strlen(buf));
	while (*pieces < ft_countl(buf))
	{
		trim = ft_strcat(trim, ft_is_line_hor(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_line_ver(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_s(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_s_up(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_z(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_lhorl(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_lhorr(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_lverr(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_lverl(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_square(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_lrevhorl(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_lrevhorr(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_lrevverr(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_lrevverl(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_z_up(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_t(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_t_left(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_t_right(tab, buf, pieces));
		trim = ft_strcat(trim, ft_is_t_up(tab, buf, pieces));
		printf("pieces = %d\n", *pieces);
		printf("countl = %d\n", ft_countl(buf));
		*pieces += 5;
	}
	printf("%s", trim);
	return (trim);
}

char	*ft_sub_trim(char **tab, char *buf)
{
	int		*pieces;
	char	*trim;

	pieces = (int *)malloc(sizeof(int));
	*pieces = 0;
	trim = ft_trim(tab, buf, pieces);
	return (trim);
}
