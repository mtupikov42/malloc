/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:12:54 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:22:08 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *restrict memptr1,
		const void *restrict memptr2, const size_t num)
{
	char	*mem1;
	char	*mem2;
	size_t	i;

	i = 0;
	mem1 = (char *)memptr1;
	mem2 = (char *)memptr2;
	while (i < num)
	{
		if (mem1[i] != mem2[i])
			return ((unsigned char)mem1[i] - (unsigned char)mem2[i]);
		i++;
	}
	return (0);
}
