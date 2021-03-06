/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <hdecaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 11:56:36 by hdecaux           #+#    #+#             */
/*   Updated: 2016/11/12 17:30:19 by hdecaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int a)
{
	if (a == '\t' || a == ' ' || a == '\n' || a == '\v' || a == '\f' \
		|| a == '\r')
		return (1);
	else
		return (0);
}
