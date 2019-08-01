/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 23:22:48 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 15:55:36 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_splitdel(char ***split)
{
	char	**str;
	int		i;

	i = 0;
	if (split && *split)
	{
		str = *split;
		while (*str)
		{
			ft_strdel(str);
			i++;
			str = &(*split)[i];
		}
		ft_memdel((void **)split);
	}
	return (0);
}
